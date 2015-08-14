set(ExternalTemplate_SRCS
  itkSomeFile.cxx
  )

add_library(ExternalTemplate ${ExternalTemplate_SRCS})
itk_module_link_dependencies()
itk_module_target(ExternalTemplate)
