itk_module_test()

set({{ cookiecutter.module_name }}Tests
  itkMinimalStandardRandomVariateGeneratorTest.cxx
  itkNormalDistributionImageSourceTest.cxx
  itk{{ cookiecutter.filter_name }}Test.cxx
  )

CreateTestDriver({{ cookiecutter.module_name }} "${{ '{' }}{{ cookiecutter.module_name -}}-Test_LIBRARIES}" "${{ '{' }}{{ cookiecutter.module_name }}Tests}")

itk_add_test(NAME itkMinimalStandardRandomVariateGeneratorTest
  COMMAND {{ cookiecutter.module_name }}TestDriver itkMinimalStandardRandomVariateGeneratorTest
  )

itk_add_test(NAME itk{{ cookiecutter.filter_name }}Test
  COMMAND {{ cookiecutter.module_name }}TestDriver
    --compare
    ${ITK_TEST_OUTPUT_DIR}/itk{{ cookiecutter.filter_name }}TestOutput.mha
    DATA{Baseline/itk{{ cookiecutter.filter_name }}TestOutput.mha}
  itk{{ cookiecutter.filter_name }}Test
    ${ITK_TEST_OUTPUT_DIR}/itk{{ cookiecutter.filter_name }}TestOutput.mha
  )

itk_add_test(NAME itkNormalDistributionImageSourceTest
  COMMAND {{ cookiecutter.module_name }}TestDriver --without-threads
  --compare
    ${ITK_TEST_OUTPUT_DIR}/itkNormalDistributionImageSourceTestOutput.mha
    DATA{Baseline/itkNormalDistributionImageSourceTestOutput.mha}
  itkNormalDistributionImageSourceTest
    ${ITK_TEST_OUTPUT_DIR}/itkNormalDistributionImageSourceTestOutput.mha
  )
