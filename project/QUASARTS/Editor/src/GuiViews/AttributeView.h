#pragma once
#include "QuasartsEngine.h"
#include <string>
#include "GuiViews/GuiView.h"
#include "Core/StaticReflection.h"
#include <memory>
#include <map>
#include <unordered_map>
#include <functional>

class AttributeView : public GuiView
{
public:
	
	void on_add() override;
	void on_gui() override;
	void on_remove() override;

	bool game = false;
private:
	size_t current_entity_id;
	void show_transform();
	void change_transform(Engine::TransformComponent*, float[], float[], float[]);
	void show_mesh();

	
	/********************** drawfunctions ************************************/
	static void draw_property(std::string name, glm::vec2 target);
	static void draw_property(std::string name, glm::vec3 target);
	static void draw_property(std::string name, glm::vec4 target);
	static void draw_property(std::string name, std::string target);
	/********************** drawfunctions ************************************/


	template <typename T>
	void show_property(T&& obj)
	{
		if constexpr (std::is_class_v<std::decay_t<T>>)
		{
			foreach(obj, [](auto&& name, auto&& value)
				{
					AttributeView::draw_property(name, value);
				});
		}
	}
};
