ITKModuleTemplate
=================

.. |CircleCI| image:: https://circleci.com/gh/InsightSoftwareConsortium/ITKModuleTemplate.svg?style=shield
    :target: https://circleci.com/gh/InsightSoftwareConsortium/ITKModuleTemplate

.. |TravisCI| image:: https://travis-ci.org/InsightSoftwareConsortium/ITKModuleTemplate.svg?branch=master
    :target: https://travis-ci.org/InsightSoftwareConsortium/ITKModuleTemplate

.. |AppVeyor| image:: https://img.shields.io/appveyor/ci/itkrobot/itkmoduletemplate.svg
    :target: https://ci.appveyor.com/project/itkrobot/itkmoduletemplate

=========== =========== ===========
   Linux      macOS       Windows
=========== =========== ===========
|CircleCI|  |TravisCI|  |AppVeyor|
=========== =========== ===========

This is a module for the `Insight Toolkit (ITK) <http://itk.org>`_ for
segmentation and registration. It is designed to work with the ITK modular
system.

This module is a template to be used as a starting point for a new ITK module.


Getting Started
---------------

The following will get an external module started in a new repository::

  python -m pip install cookiecutter
  python -m cookiecutter gh:InsightSoftwareConsortium/ITKModuleTemplate
  # Fill in the information requested at the prompts

Reasonable defaults will be provided for all of the parameters. The parameters are:

*full_name*
  Your full name.

*email*
  Your email.

*github_username*
  Your GitHub username.

*project_name*
  This is a name for the project, which is *ITK* followed by the
  module name, by convention. Examples include *ITKIsotropicWavelets* or
  *ITKBoneMorphometry*.

*module_name*
  This is the name of the module. Since this is an external module, it does
  not start with the *ITK* prefix. It is in CamelCase, by convention. Examples
  include *IsotropicWavelets* and *BoneMorphometry*.

*filter_name*
  The skeleton of an ``itk::ImageToImageFilter`` will be created by default.
  Optionally specify this value, if you will be adding an
  ``itk::ImageToImageFilter`` to your module.

*python_package_name*
  This is the name of the Python package that will be created from the module.
  By convention, this is *itk-<project_name in lower case>*. For example,
  *itk-isotropicwavelets* or *itk-bonemorphometry*.

*download_url*
  This is the download url added to the Python package metadata. This can be
  the GitHub repository URL.

*project_short_description*
  A short description to use in the project README, module Doxygen
  documentation, and Python package documentation.

*project_long_description*
  A long description to use in the project README, module Doxygen
  documentation, and Python package documentation.

The output of the cookiecutter is a buildable ITK external module with example
classes. Remove or replace the classes with your new classes. Push your new
module to GitHub, and enable builds on `CircleCI <https://circleci.com/>`_,
`TravisCI <https://travis-ci.org/>`_, and `AppVeyor
<https://www.appveyor.com/>`_.

Documentation on `how to populate the module
<https://itk.org/ITKSoftwareGuide/html/Book1/ITKSoftwareGuide-Book1ch9.html#x50-1430009>`_
can be found in the `ITK Software Guide <https://itk.org/ITKSoftwareGuide/html/>`_.

To improve the discoverability of your module on GitHub, first push the
associated repository, then add `itk-module
<https://github.com/topics/itk-module>`_ to the project's `GitHub Topics
<https://help.github.com/articles/about-topics/>`_ .


Remote Module
-------------

After an `Insight Journal <http://www.insight-journal.org/>`_ article has been
submitted, the module can be included in ITK as a `remote module
<http://www.itk.org/Wiki/ITK/Policy_and_Procedures_for_Adding_Remote_Modules>`_.
Add a file in "ITK/Modules/Remote" called "YourModule.remote.cmake", for this
module it would be "ExternalExample.remote.cmake" with the followlowing
contents::

  itk_fetch_module(MyModule
    "A description of the a module."
    GIT_REPOSITORY http://github.com/myuser/ITKMyModule.git
    GIT_TAG abcdef012345
    )


Python Packages
---------------

Continuous integration service configurations are included to build Python
packages for Linux, macOS, and Windows. These packages can be `downloaded
<https://itkpythonpackage.readthedocs.io/en/latest/Build_ITK_Module_Python_packages.html#github-automated-ci-package-builds>`_
and `uploaded to the Python Package Index (PyPI)
<https://itkpythonpackage.readthedocs.io/en/latest/Build_ITK_Module_Python_packages.html#upload-the-packages-to-pypi>`_.


ITKv4 Branch
------------
In the transition to the major release of ITKv5 your module might want to be compatible with both versions: ITKv4 and ITKv5.
In order to do that, keep the master branch for development with ITKv5, and create another branch, named ``ITKv4``, or ``release``,
that is compatible with the version 4.13 of ITK.
For examples and updated information on how to do this: please `check the discourse conversation
<https://discourse.itk.org/t/itk-external-module-github-builds-for-4-x-and-5-x/900>`_.


License
-------

This software is distributed under the Apache 2.0 license. Please see
the *LICENSE* file for details.


Authors
-------

* Bradley Lowekamp
* Matt McCormick
* Jean-Baptiste VIMORT
