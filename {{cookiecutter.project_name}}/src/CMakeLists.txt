set({{ cookiecutter.module_name }}_SRCS
  itkMinimalStandardRandomVariateGenerator.cxx
  )

itk_module_add_library({{ cookiecutter.module_name }} ${{ '{' }}{{ cookiecutter.module_name }}_SRCS{{ '}' }})
