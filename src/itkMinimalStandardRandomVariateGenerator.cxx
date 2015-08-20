/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkMinimalStandardRandomVariateGenerator.h"

namespace itk
{
namespace Statistics
{

MinimalStandardRandomVariateGenerator
::MinimalStandardRandomVariateGenerator()
{
  this->Initialize( 1 );
}


MinimalStandardRandomVariateGenerator
::~MinimalStandardRandomVariateGenerator()
{
}


void
MinimalStandardRandomVariateGenerator
::Initialize(IntegerType randomSeed)
{
  this->m_Generator.seed( randomSeed );
}


MinimalStandardRandomVariateGenerator::IntegerType
MinimalStandardRandomVariateGenerator
::GetIntegerVariate()
{
  return this->m_Generator();
}


double
MinimalStandardRandomVariateGenerator
::GetVariate()
{
  return this->m_Generator() / static_cast< double >( this->m_Generator.max() );
}


void
MinimalStandardRandomVariateGenerator
::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);
}

} // end namespace Statistics
} // end namespace itk
