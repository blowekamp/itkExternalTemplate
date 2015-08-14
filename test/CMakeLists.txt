itk_module_test()

set(ExternalTemplateTests
  itkEmptyTest.cxx
  )

CreateTestDriver(ExternalTemplate "${ExternalTemplate-Test_LIBRARIES}" "${ExternalTemplateTests}")

itk_add_test(NAME itkDeleteMeEmptyTest
  COMMAND ExternalTemplateTestDriver itkEmptyTest "argument1" "...")
