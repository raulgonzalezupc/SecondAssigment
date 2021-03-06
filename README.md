<h1 align="center" style="border-bottom: none;">Morgoth Engine</h1>

## Morgoth Engine
- Game Engine developed with C++.
- Libraries used: [SDL 2.0](https://www.libsdl.org/), [glew 2.1.0](http://glew.sourceforge.net/), [MathGeoLib 3.0.0](https://github.com/juj/MathGeoLib/), [Dear ImGui 1.73](https://github.com/ocornut/imgui/), [DevIL 1.8](http://openil.sourceforge.net/), [assimp 5.0](https://github.com/assimp/assimp/), [OpenGL](https://www.opengl.org/), [Rapidjson 1.1.0](https://github.com/Tencent/rapidjson/).

- Project developed for [UPC programming AAA videogames master's degree](https://www.talent.upc.edu/ing/estudis/formacio/curs/201200/master-degree-advanced-programming-aaa-videogames/).


- Repository: https://github.com/raulgonzalezupc/SecondAssigment

- Licence: This project is licensed under the MIT License - see the [LICENSE](https://github.com/raulgonzalezupc/SecondAssigment/blob/master/LICENSE) file for details.

## How to use it
- First of all, its going to load the default model with its texture from the Assets Folder.

- The models Fbx contained on the folder `Assets` will be imported to a new folder `Library/Meshes` as a binary format file. 

- Unity-like controls.

- `RightClick` + `W` `A` `S` `D` `Q` &rarr; For moving arround the scene.
- If you want to speed up the movement, just press `Left Shift` while movint to double the speed. 

- `RightClick` + Mouse movement &rarr; FPS camera

- `Alt` + `Left Click` &rarr; Orbit arround the model.

- `MouseWheel` &rarr; Zoom

- If you want to load another one, just drag it from anywhere of your hard drive!

- Pressing `ESC` will quit the app.

- If You want to focus on the model, press `F`.


## Parts

- Raúl González:
	- Implementation and creation of FrameBuffer. 
	- Implementation and creation of the class GameObject.
	- Implementation and creation of classes: Component, ComponentMesh, ComponentTransform, ComponentMaterial and ComponentCamera.
	- Implementation and creation of Module Scene with the creation of the Game Object root, scene and Game. 
	- Implementation and creation of the Hierarchy with Imgui.
	- Implementation and creation of the Timer class with the restriction of fps and the clock. 
	- Implementation of the ImGui Docking. 
	- Implementation of the DebugDraw class. 
	- Creation of the AABB of the Game Objects. 
	- Creation of the class Skybox and the respective shaders. 
	
- Ricard Vivó:
	- Refactoration of the Orbit movement in the camera.
	- Implementation of the fbx model import from the ../Assets folder.
	- Implementation creation of the Binary File for the Mesh and creation of the directory Library/Mesh.
	- Implementation to process the Mesh binary file and its nodes/meshes though the binary file.
	- Mesh class refactoring to fit the Mesh importer.
	- Refactoring of the Old Model Class into the Scene for a later Scene Serialization.
	


## Authors
| [![Raúl Golzález](https://github.com/raulgonzalezupc.png?size=10)](https://github.com/raulgonzalezupc) | [![Ricard Vivó Montero](https://github.com/RickyVimon.png?size=100)](https://github.com/RickyVimon) |
| ---- | ---- |
| [Raúl Golzález](https://github.com/raulgonzalezupc/) | [Ricard Vivó Montero](https://github.com/RickyVimon/) |



 
