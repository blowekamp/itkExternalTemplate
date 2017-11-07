itk_module_test()

set({{ cookiecutter.module_name }}Tests
  itkMinimalStandardRandomVariateGeneratorTest.cxx
  itkNormalDistributionImageSourceTest.cxx
  )

CreateTestDriver({{ cookiecutter.module_name }} "${{ '{' }}{{ cookiecutter.module_name -}}-Test_LIBRARIES}" "${{ '{' }}{{ cookiecutter.module_name }}Tests}")

itk_add_test(NAME itkMinimalStandardRandomVariateGeneratorTest
  COMMAND {{ cookiecutter.module_name }}TestDriver itkMinimalStandardRandomVariateGeneratorTest
  )

itk_add_test(NAME itkNormalDistributionImageSourceTest
  COMMAND {{ cookiecutter.module_name }}TestDriver --without-threads
  --compare
    ${ITK_TEST_OUTPUT_DIR}/itkNormalDistributionImageSourceTestOutput.mha
    DATA{Baseline/itkNormalDistributionImageSourceTestOutput.mha}
  itkNormalDistributionImageSourceTest
    ${ITK_TEST_OUTPUT_DIR}/itkNormalDistributionImageSourceTestOutput.mha
  )
