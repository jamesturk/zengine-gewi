Index
------------------------------------------------------------
I.   About Gewi
II.  Getting Gewi
III. Building Gewi
IV.  Using Gewi
V.   Legal Overview
VI.  History of Gewi
------------------------------------------------------------
I. About Gewi

Gewi is a GUI library designed for use with ZEngine, information on ZEngine
can be found at http://zengine.sourceforge.net/.
------------------------------------------------------------
II. Getting Gewi:

Gewi is available from the same places that ZEngine is:
Support comes from: http://conceptofzero.net/
The sourceforge page: http://zengine.sourceforge.net/
The project page: http://sourceforge.net/projects/zengine/
The CVS page: http://sourceforge.net/cvs/?group_id=62098
------------------------------------------------------------
III. Building Gewi:

ZEngine can be built on any system that has SDL and OpenGL available.  It is
currently being developed Windows XP (Redhat 8 support soon).  If you are in
VC++ the folder vc7 contains project files for use, and if you are in mingw 
or cygwin you can change the linux makefile to suit your needs.
-If you are using VC++ you will need to add the path to the dependencies (SDL 
and others) as well as the path to ZEngine before building.
If you are having a problem building ask at 
http://www.conceptofzero.net/forums/index.php?act=SF&f=15
------------------------------------------------------------
IV. Using Gewi:

Gewi requires a working copy of ZEngine, if your compiler/environment 
supports ZEngine it should support Gewi as well.  Gewi tutorials and 
documentation is not yet complete if you would like to write any submit
them to james@conceptofzero.net and I'll make sure they get out and you get
proper credit. 
------------------------------------------------------------
V. Legal Overview:

See ZEngine's readme.txt for a Legal Overview of using libraries 
that are dependent upon LGPL based libraries, using Gewi is the same
since it includes no new LGPL code.
------------------------------------------------------------
History of ZEngine:
    Since most of the improvements will just be more widgets I
am much more open to outside help for Gewi than ZEngine which is mostly
my own work, I am going to depend on community support to add new widgets
to Gewi, I can't possibly add every single widget people need while working
on ZEngine and other projects.
    0.1 was a basic release, just to show some people how I planned to 
do the long promised GUI library for ZEngine.  I rewrote this twice using
callbacks one time and a different way of handling child windows another,
but I found a way that seemed easy to use and easy to extend and that is what
has become 0.2. 

    -James Turk james@conceptofzero.net
