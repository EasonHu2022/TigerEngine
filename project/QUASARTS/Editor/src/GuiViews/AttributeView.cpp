#include "MenuBarView.h"
#include <iostream>
// Decide OS
#include "AttributeView.h"


void AttributeView::on_add()
{
	QDEBUG("on add view : MenuBar");
}

void AttributeView::on_gui()
{
	
	if (FileModule::Instance()->get_root() != NULL) {

		ImGui::SetNextWindowPos(ImVec2(window->get_width() * 0.85625+18, 18));
		ImGui::SetNextWindowSize(ImVec2(window->get_width() * 0.34375, window->get_height() * 1.0922222222+41));
		ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		current_entity_id = Engine::ECSManager::Instance()->get_current_entity();
		if (current_entity_id == TOO_MANY_ENTITIES) return;
		if (!game) {
			ImGui::Text("How to get entity name?");
			auto componentList = Engine::ECSManager::Instance()->get_all_component_types(current_entity_id);
			for (auto componentType : componentList)
			{
				switch (componentType)
				{
				case COMPONENT_TRANSFORM :
				{
					ImGui::Text("Transform");
					Engine::TransformComponent* componentTR = Engine::ECSManager::Instance()->get_component<Engine::TransformComponent>(current_entity_id, componentType);
					show_property(*componentTR);
					break;
				}
					
				case COMPONENT_LIGHTING:
				{
					ImGui::Text("Lighting");
					Engine::LightComponent* componentL = Engine::ECSManager::Instance()->get_component<Engine::LightComponent>(current_entity_id, componentType);
					show_property(*componentL);
					break;
				}
					
				case COMPONENT_MATERIAL:
				{
					ImGui::Text("Material");
					Engine::MaterialComponent* componentM = Engine::ECSManager::Instance()->get_component<Engine::MaterialComponent>(current_entity_id, componentType);
					show_property(*componentM);
					break;
				}
					
				case COMPONENT_MESH:
				{
					ImGui::Text("Mesh");
					Engine::MeshComponent* componentMe = Engine::ECSManager::Instance()->get_component<Engine::MeshComponent>(current_entity_id, componentType);
					show_property(*componentMe); 
					break;
				}
					
				case COMPONENT_SCRIPT:
				{
					ImGui::Text("Script");
					Engine::ScriptComponent* componentS = Engine::ECSManager::Instance()->get_component<Engine::ScriptComponent>(current_entity_id, componentType);
					show_property(*componentS);
					break;
				}
				default:
					QERROR("unknown type : {0}", componentType);
					break;
				}
				
			}
		
		}
		ImGui::End();

	}
}

void AttributeView::on_remove()
{
	QDEBUG("on remove view : MenuBar");
}

void AttributeView::show_mesh() {
	Engine::MeshComponent* mesh = Engine::ECSManager::Instance()->get_component<Engine::MeshComponent>(Engine::ECSManager::Instance()->get_current_entity(), COMPONENT_MESH);
	std::string obj_name = "Name of mesh file: " + mesh->path.substr(mesh->path.find_last_of("\\") + 1);
	ImGui::Separator();
	ImGui::Text(obj_name.c_str());
}

void AttributeView::draw_property(std::string name, glm::vec2 _target)
{
	
	
}

void AttributeView::draw_property(std::string name, glm::vec3 _target)
{
	ImGui::InputFloat3(name.data(), glm::value_ptr(_target),"%.3f",ImGuiInputTextFlags_::ImGuiInputTextFlags_AutoSelectAll);
}

void AttributeView::draw_property(std::string name, glm::vec4 _target)
{

}

void AttributeView::draw_property(std::string name, std::string _target)
{

}

void AttributeView::show_transform() {
	ImGui::Separator();
	Engine::TransformComponent* transform = Engine::ECSManager::Instance()->get_component<Engine::TransformComponent>(Engine::ECSManager::Instance()->get_current_entity(), COMPONENT_TRANSFORM);
	show_property(*transform);
	
	
	//static float pos[3] = { transform->position.x ,transform->position.y, transform->position.z };
	//static float rot[3] = { transform->rotation.x ,transform->rotation.y, transform->rotation.z };
	//static float scal[3] = { transform->scale.x ,transform->scale.y, transform->scale.z };

	//static int mode = 0;
	//ImGui::RadioButton("Translate", &mode, ImGuizmo::OPERATION::TRANSLATE); ImGui::SameLine();
	//ImGui::RadioButton("Rotate", &mode, ImGuizmo::OPERATION::ROTATE); ImGui::SameLine();
	//ImGui::RadioButton("Scale", &mode, ImGuizmo::OPERATION::SCALE);
	//transform->operation = (ImGuizmo::OPERATION)mode;

	//ImGui::InputFloat3(" Position", pos);
	//ImGui::InputFloat3(" Rotation", rot);
	//ImGui::InputFloat3(" Scale", scal);

	//if (ImGui::IsWindowFocused()) {
	//	transform->position.x = pos[0];
	//	transform->position.y = pos[1];
	//	transform->position.z = pos[2];

	//	transform->rotation.x = rot[0];
	//	transform->rotation.y = rot[1];
	//	transform->rotation.z = rot[2];

	//	transform->scale.x = scal[0];
	//	transform->scale.y = scal[1];
	//	transform->scale.z = scal[2];
	//}
	//else {
	//	pos[0] = transform->position.x;
	//	pos[1] = transform->position.y;
	//	pos[2] = transform->position.z;
	//	rot[0] = transform->rotation.x;
	//	rot[1] = transform->rotation.y;
	//	rot[2] = transform->rotation.z;
	//	scal[0] = transform->scale.x;
	//	scal[1] = transform->scale.y;
	//	scal[2] = transform->scale.z;
	//}
	//
}

void AttributeView::change_transform(Engine::TransformComponent* transform, float* pos, float* rot, float* scal) {

}