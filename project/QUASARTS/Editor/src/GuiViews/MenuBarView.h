#pragma once
#include "QuasartsEngine.h"
#include <string>
#include "GuiViews/FileInputView.h"

class MenuBarView : public GuiView
{
public:
	bool new_project;
	bool new_scene;
	bool new_script;
	bool new_entity;
	bool new_child;
	bool new_attribute;
	std::string folder_path;
	std::string project_name;
	static std::string OpenFileDialogue(const wchar_t*);
	static std::string OpenFolderDialogue();
	void load_object(std::string, std::string);
	void newProject();
	void newScene();
	void newScript();
	void newEntity();
	void newChild();
	void newAttribute();
	const char* components[4] = { "Transform", "Mesh", "Colision", "Script"};
public:
	void on_add() override;
	void on_gui() override;
	void on_remove() override;
};
