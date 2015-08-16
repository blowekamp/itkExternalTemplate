itk_module_test()

set(ModuleTemplateTests
  itkEmptyTest.cxx
  itkLogNormalDistributionImageSourceTest.cxx
  )

CreateTestDriver(ModuleTemplate "${ModuleTemplate-Test_LIBRARIES}" "${ModuleTemplateTests}")

itk_add_test(NAME itkDeleteMeEmptyTest
  COMMAND ModuleTemplateTestDriver itkEmptyTest "argument1" "...")

itk_add_test(NAME itkLogNormalDistributionImageSourceTest
  COMMAND ModuleTemplateTestDriver --without-threads itkLogNormalDistributionImageSourceTest
    ${ITK_TEST_OUTPUT_DIR}/itkLogNormalDistributionImageSourceTestOutput.mha
    )
