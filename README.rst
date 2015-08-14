General
=======

This is a module for `ITK <http://itk.org>`_: The Insight Toolkit for
Segmentation and Registration. It is designed to work with the ITKv4 modular
system and to be placed in ITK/Modules/External or used as a Remote module.

This module is empty. It is a template that is a starting point for a module
with actual content.

Getting Started
===============

The official ITKv4 Wiki documentation on adding an external module is here:

*  http://www.itk.org/Wiki/ITK_Release_4/Modularization/Add_an_external_module_(external_module)
*  http://www.itk.org/Wiki/ITK/Policy_and_Procedures_for_Adding_Remote_Modules


External Module
---------------

The following is a brief list of instructions to get a external module
started in a repository::

  mkdir ITK/Modules/External/ITKMyModule
  cd ITK/Modules/External/ITKMyModule
  git init
  git fetch git@github.com:InsightSoftwareConsortium/ITKModuleTemplate.git
  git merge FETCH_HEAD

Remote Module
-------------

After a module has been created as a git repository it can be included
as a remote module, which enables automatic fetching. Add a file in
"ITK/Modules/Remote" called "YourModule.remote.cmake", for this module
it would be "ExternalExample.remote.cmake" with the followlowing contents::

  itk_fetch_module(MyModule
    "A description of the a module."
    GIT_REPOSITORY http://github.com/myuser/ITKMyModule.git
    GIT_TAG abcdef012345
    )

Editing
-------

The CMakeLists.txt and itk-modules need to be modified with the name
of the module, something along the following::

  sed 's/ExternalTemplate/MyModule/g' CMakeLists.txt itk-module.cmake

There is the inplace option to sed, but it's not portable, so do this
change by hand or look up the option in sed.

Then hack away at you code in `include`, `src`, and `test`.

License
=======

This software is distributed under the Apache License. Please see
LICENSE for details.


Authors
=======

* Bradley Lowekamp
* Matt McCormick
