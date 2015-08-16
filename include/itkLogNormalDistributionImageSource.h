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
#ifndef itkLogNormalDistributionImageSource_h
#define itkLogNormalDistributionImageSource_h

#include "itkGenerateImageSource.h"

namespace itk
{

/** \class LogNormalDistributionImageSource
 *
 * \brief Generate a image of pixels sampled from a log-normal distribution.
 *
 * Real-valued pixels are sampled from a log-normal distribution.
 *
 */
template< typename TImage >
class LogNormalDistributionImageSource: public GenerateImageSource< TImage >
{
public:
  typedef TImage                        ImageType;
  typedef typename ImageType::PixelType PixelType;

  /** Standard class typedefs. */
  typedef LogNormalDistributionImageSource Self;
  typedef GenerateImageSource< ImageType > Superclass;
  typedef SmartPointer< Self >             Pointer;
  typedef SmartPointer< const Self >       ConstPointer;

  itkStaticConstMacro( ImageDimension, unsigned int, ImageType::ImageDimension );

  /** Run-time type information. */
  itkTypeMacro( LogNormalDistributionImageSource, GenerateImageSource );

  /** Standard New macro. */
  itkNewMacro( Self );

  /** Seed for random initialization  */
  itkGetConstMacro(Seed, uint32_t);
  itkSetMacro(Seed, uint32_t);

  /** Mean of the of the underlying normal distribution. */
  itkGetConstMacro(Mu, PixelType);
  itkSetMacro(Mu, PixelType);

  /** Standard deviation of the of the underlying normal distribution. */
  itkGetConstMacro(Sigma, PixelType);
  itkSetMacro(Sigma, PixelType);

protected:
  LogNormalDistributionImageSource();
  virtual ~LogNormalDistributionImageSource() {}

  void PrintSelf( std::ostream& os, Indent indent ) const ITK_OVERRIDE;

  typedef typename ImageType::RegionType OutputRegionType;

  virtual void ThreadedGenerateData( const OutputRegionType & outputRegion, ThreadIdType threadId ) ITK_OVERRIDE;

private:
  LogNormalDistributionImageSource( const Self& ); // purposely not implemented
  void operator=( const Self& ); // purposely not implemented

  uint32_t m_Seed;

  PixelType m_Mu;
  PixelType m_Sigma;

#ifdef ITK_USE_CONCEPT_CHECKING
  itkConceptMacro( FloatingPointPixel, ( itk::Concept::IsFloatingPoint< typename ImageType::PixelType > ) );
#endif
};
}

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkLogNormalDistributionImageSource.hxx"
#endif

#endif // itkLogNormalDistributionImageSource_h
