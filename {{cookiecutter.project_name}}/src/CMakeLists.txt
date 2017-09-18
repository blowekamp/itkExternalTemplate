set({{ cookiecutter.module_name }}_SRCS
  itkMinimalStandardRandomVariateGenerator.cxx
  )

add_library({{ cookiecutter.module_name }} ${{ '{' }}{{ cookiecutter.module_name }}_SRCS{{ '}' }})
itk_module_link_dependencies()
itk_module_target({{ cookiecutter.module_name}})
