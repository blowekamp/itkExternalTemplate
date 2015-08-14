itk_module_test()

set(ModuleTemplateTests
  itkEmptyTest.cxx
  )

CreateTestDriver(ModuleTemplate "${ModuleTemplate-Test_LIBRARIES}" "${ModuleTemplateTests}")

itk_add_test(NAME itkDeleteMeEmptyTest
  COMMAND ModuleTemplateTestDriver itkEmptyTest "argument1" "...")
