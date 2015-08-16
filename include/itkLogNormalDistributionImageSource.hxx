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

#include "itkImageScanlineIterator.h"
#include "itkProgressReporter.h"

#include <random>

namespace itk
{

template< typename TImage >
LogNormalDistributionImageSource< TImage >
::LogNormalDistributionImageSource():
  m_Seed( 1 ),
  m_Mu( 0.0 ),
  m_Sigma( 1.0 )
{
}


template< typename TImage >
void
LogNormalDistributionImageSource< TImage >
::PrintSelf( std::ostream& os, Indent indent ) const
{
  Superclass::PrintSelf( os, indent );

  os << indent << "Seed: " << this->GetSeed() << std::endl;
  os << indent << "Mu: " << this->GetMu() << std::endl;
  os << indent << "Sigma: " << this->GetSigma() << std::endl;
}


template< typename TImage >
void
LogNormalDistributionImageSource< TImage >
::ThreadedGenerateData( const OutputRegionType & outputRegion, ThreadIdType threadId )
{
  ImageType * output = this->GetOutput();

  int seeds[threadId];
  for( ii: seeds )
    {
    seeds[ii] = this->GetSeed() + ii;
    }
  std::seed_seq seedSeq(seeds, seeds + threadId);
  std::vector< uint32_t > generatedSeeds( threadId + 1 );
  seedSeq.generate(generatedSeeds.begin(), generatedSeeds.end());

  typedef typename ImageType::PixelType PixelType;
  typedef std::lognormal_distribution< PixelType > LogNormalDistributionType;
  LogNormalDistributionType logNormalDistribution( this->GetMu(), this->GetSigma() );
  std::mt19937 generator( generatedSeeds[threadId] );

  const SizeValueType size0 = outputRegion.GetSize( 0 );
  if( size0 == 0 )
    {
    return;
    }
  const SizeValueType numberOfLinesToProcess = outputRegion.GetNumberOfPixels() / size0;

  typedef ImageScanlineIterator< ImageType > IteratorType;
  IteratorType it( output, outputRegion );
  ProgressReporter progress( this, threadId, numberOfLinesToProcess );

  while( !it.IsAtEnd() )
    {
    while( !it.IsAtEndOfLine() )
      {
      it.Set( logNormalDistribution( generator ) );
      ++it;
      }
    it.NextLine();
    progress.CompletedPixel();
    }
}

} // end namespace itk

#endif // itkLogNormalDistributionImageSource_hxx
