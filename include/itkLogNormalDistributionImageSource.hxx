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
#ifndef itkLogNormalDistributionImageSource_hxx
#define itkLogNormalDistributionImageSource_hxx

#include "itkLogNormalDistributionImageSource.h"

#include <random>

namespace itk
{

template< typename TImage >
LogNormalDistributionImageSource< TImage >
::LogNormalDistributionImageSource()
{
}


template< typename TImage >
void
LogNormalDistributionImageSource< TImage >
::PrintSelf( std::ostream& os, Indent indent ) const
{
  Superclass::PrintSelf( os, indent );

  os << indent << "Seed: " << this->m_Seed << std::endl;
}


template< typename TImage >
void
LogNormalDistributionImageSource< TImage >
::ThreadedGenerateData( const OutputRegionType & outputRegion, ThreadIdType threadId )
{
  ImageType * output = this->GetOutput();
}

} // end namespace itk

#endif // itkLogNormalDistributionImageSource_hxx
