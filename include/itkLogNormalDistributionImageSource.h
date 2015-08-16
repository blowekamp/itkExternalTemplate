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

#include "itkImageSource.h"

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
class LogNormalDistributionImageSource: public ImageSource< TImage >
{
public:
  /** Standard class typedefs. */
  typedef TImage ImageType;

  typedef LogNormalDistributionImageSource Self;
  typedef ImageSource< ImageType >         Superclass;
  typedef SmartPointer< Self >             Pointer;
  typedef SmartPointer< const Self >       ConstPointer;

  itkStaticConstMacro( ImageDimension, unsigned int, ImageType::ImageDimension );

  /** Run-time type information. */
  itkTypeMacro( LogNormalDistributionImageSource, ImageSource );

  /** Standard New macro. */
  itkNewMacro( Self );

protected:
  LogNormalDistributionImageSource();
  virtual ~LogNormalDistributionImageSource() {}

  void PrintSelf( std::ostream& os, Indent indent ) const ITK_OVERRIDE;

private:
  LogNormalDistributionImageSource( const Self& ); // purposely not implemented
  void operator=( const Self& ); // purposely not implemented
};
}

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkLogNormalDistributionImageSource.hxx"
#endif

#endif // itkLogNormalDistributionImageSource_h
