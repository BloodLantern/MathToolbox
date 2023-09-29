from distutils.core import setup, Extension

from Cython.Distutils import build_ext
from distutils.core import setup
import os
import sysconfig

# EDITABLE VARIABLES
source_extensions = ['.cpp', '.cxx']
module_name = 'test'
include_dirs = ['include']
source_base_dirs = ['src', 'wraps']
additional_compiler_args = ['/std:c++20', '/MP']

# Function to remove library file suffix
class NoSuffixBuilder(build_ext):
    def get_ext_filename(self, ext_name):
        filename = super().get_ext_filename(ext_name)
        suffix = sysconfig.get_config_var('EXT_SUFFIX')
        ext = os.path.splitext(filename)[1]
        return filename.replace(suffix, "") + ext
    
source_files = []

# Recursively walk through all files starting in 'dir_path' to get the source ones
def walk_dir(dir_path):
    for root, subdirs, files in os.walk(os.path.abspath(dir_path)):
        for filename in files:
            file_path = os.path.join(root, filename)
            if os.path.splitext(file_path)[1] in source_extensions:
                source_files.append(file_path)

for dir in source_base_dirs:
    walk_dir(dir)

module = Extension(
    '_' + module_name,
    sources=source_files,
    include_dirs=include_dirs,
    language='c++',
    extra_compile_args=additional_compiler_args
)

setup(
    name = module_name,
    ext_modules = [module],
    py_modules = [module_name],
    cmdclass={"build_ext": NoSuffixBuilder}
)
