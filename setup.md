# Xcode (macOS only)

First, run Xcode, and create a new Project (File > New > Project...). Select Command Line Tool and click 'Next'. Name your Project, for example, "Tutorial" in the 'Product Name' text field. Double check that 'Language' is set to C++ and click 'Next'. Now select a location to save the project, uncheck 'Create Git repository' and click 'Create'. You should delete the main.cpp file that is created.

Following this, you will need to link the OpenGL and FreeGLUT frameworks. These are packaged with the latest versions of OS X (relabelling FreeGLUTas GLUT for compatibility).

In the properties for your Project, navigate to 'Build Phases'. Under 'Link Binary With Libraries', click the +. In the list of framework and libraries, search for 'OpenGL.framework', select it and click 'Add'. Repeat this for 'GLUT.framework'.

You will also want to disable some deprecated warnings – the original GLUT is very old and many of its commands were deprecated, however freeglut is in continued development. In 'Build Settings', scroll down to 'Apple LLVM 8.0 - Custom Compiler Flags' (the version of LLVM may be different). Double-click the field right of 'Other C Flags', click the + and type "-Wno-deprecated".

Your Project is now ready to create your first 3D application.