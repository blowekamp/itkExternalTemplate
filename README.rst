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

Documentation on `how to populate the module
<https://itk.org/ITKSoftwareGuide/html/Book1/ITKSoftwareGuide-Book1ch9.html#x50-1430009>`_
can be found in the `ITK Software Guide
<https://itk.org/ITKSoftwareGuide/html/>`_.



Remote Module
-------------

After an `Insight Journal <http://www.insight-journal.org/>`_ article has been
submitted, the module can be included in ITK as a `remote module
<https://itk.org/ITKSoftwareGuide/html/Book1/ITKSoftwareGuide-Book1ch9.html#x55-1640009.7>`_.
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


License
-------

This software is distributed under the Apache 2.0 license. Please see
the *LICENSE* file for details.


Authors
-------

* Bradley Lowekamp
* Matt McCormick
* Jean-Baptiste VIMORT
