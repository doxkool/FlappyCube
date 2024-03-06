#include "Renderer/ImGui/App/SceneInspector.h"

namespace Engine
{
	SceneInspector::SceneInspector(Scene* scene)
	{
		if (!ImGui::Begin("Scene Inspector"))
		{
			ImGui::End();
			return;
		}

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
		if (ImGui::BeginTable("##split", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Entities");
			ImGui::TableSetupColumn("Contents");
			ImGui::TableHeadersRow();

			ShowEntityObject(scene);
		}

		ImGui::EndTable();

		ImGui::PopStyleVar();
		ImGui::End();
	}

	void SceneInspector::ShowEntityObject(Scene * scene)
	{
		Scene* m_scene = static_cast<Scene*>(scene);

		std::vector<Base_Entity> Data = m_scene->Entities_Data;

		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0);
		ImGui::AlignTextToFramePadding();

		bool scene_node_open = ImGui::TreeNode("Entities", "%s", m_scene->sceneName, ImGuiTreeNodeFlags_DefaultOpen);

		if (scene_node_open)
		{
			for (size_t i = 0; i < m_scene->Entities_Data.size(); i++)
			{
				int uid = m_scene->Entities_Data[i].ID;
				const char* prefix = m_scene->Entities_Data[i].name;

				glm::vec3 entityPos = m_scene->Entities_Data[i].position;
				glm::vec3 entityRot = m_scene->Entities_Data[i].rotation;
				glm::vec3 entitySca = m_scene->Entities_Data[i].scale;

				const char* texPath = m_scene->Entities_Data[i].texturePath;
				float movSpeed = m_scene->Entities_Data[i].MovementSpeed;
				bool genOverlap = m_scene->Entities_Data[i].GeneratePhysOverlap;
				bool lockScaleRatio = m_scene->Entities_Data[i].lockScaleRatio;

				// Use object uid as identifier. Most commonly you could also use the object pointer as a base ID.
				ImGui::PushID(uid);

				// Text and Tree nodes are less high than framed widgets, using AlignTextToFramePadding() we add vertical spacing to make the tree lines equal high.
				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0);
				ImGui::AlignTextToFramePadding();

				if (ImGui::TreeNodeEx(m_scene->sceneName, NULL, "%s_%u", prefix, uid))
				{
					ImGui::TableSetColumnIndex(1);

					ImGui::Separator();
					ImGui::Spacing();
					ImGui::Text("Informations");
					ImGui::Spacing();
					ImGui::Separator();

					ImGui::Text("Name: %s", m_scene->Entities_Data[i].name);
					ImGui::Text("Entity ID: %u", m_scene->Entities_Data[i].ID);

					ImGui::Separator();
					ImGui::Spacing();
					ImGui::Text("Transform");
					ImGui::Spacing();
					ImGui::Separator();

					if (ImGui::TreeNodeEx("Position", NULL, "Position"))
					{

						ImGui::Text("X: ");
						ImGui::SameLine();
						if (ImGui::DragFloat("##xPos", &entityPos.x, 1.f, NULL, NULL, "%.2f")) { Data[i].position.x = entityPos.x; }
						ImGui::Text("Y: ");
						ImGui::SameLine();
						if (ImGui::DragFloat("##yPos", &entityPos.y, 1.f, NULL, NULL, "%.2f")) { Data[i].position.y = entityPos.y; }
						if (!b_2DcoordinatesOnly)
						{
							ImGui::Text("Z: ");
							ImGui::SameLine();
							if (ImGui::DragFloat("##zPos", &entityPos.z, 1.f, NULL, NULL, "%.2f")) { Data[i].position.z = entityPos.z; }
						}

						ImGui::TreePop();
						ImGui::Spacing();
						ImGui::Separator();
					}
					else
					{
						if (!b_2DcoordinatesOnly)
						{
							ImGui::SameLine();
							ImGui::Text("X: %.2f | ", entityPos.x);
							ImGui::SameLine();
							ImGui::Text("Y: %.2f | ", entityPos.y);
							ImGui::SameLine();
							ImGui::Text("Z: %.2f", entityPos.z);
						}
						else
						{
							ImGui::SameLine();
							ImGui::Text("X: %.2f | ", entityPos.x);
							ImGui::SameLine();
							ImGui::Text("Y: %.2f", entityPos.y);
						}
					}

					if (ImGui::TreeNodeEx("Rotation", NULL, "Rotation"))
					{
						if (!b_2DcoordinatesOnly)
						{
							ImGui::Text("X: ");
							ImGui::SameLine();
							if (ImGui::DragFloat("##xRot", &entityRot.x, 1.f, NULL, NULL, "%.2f")) { Data[i].rotation.x = entityRot.x; }
							ImGui::Text("Y: ");
							ImGui::SameLine();
							if (ImGui::DragFloat("##yRot", &entityRot.y, 1.f, NULL, NULL, "%.2f")) { Data[i].rotation.y = entityRot.y; }
							ImGui::Text("Z: ");
							ImGui::SameLine();
							if (ImGui::DragFloat("##zRot", &entityRot.z, 1.f, NULL, NULL, "%.2f")) { Data[i].rotation.z = entityRot.z; }
						}
						else
						{
							ImGui::Text("   ");
							ImGui::SameLine();
							if (ImGui::DragFloat("##zRot", &entityRot.z, 1.f, NULL, NULL, "%.2f")) { Data[i].rotation.z = entityRot.z; }
						}

						ImGui::TreePop();
						ImGui::Spacing();
						ImGui::Separator();
					}
					else
					{
						if (!b_2DcoordinatesOnly)
						{
							ImGui::SameLine();
							ImGui::Text("X: %.2f | ", entityRot.x);
							ImGui::SameLine();
							ImGui::Text("Y: %.2f | ", entityRot.y);
							ImGui::SameLine();
							ImGui::Text("Z: %.2f", entityRot.z);
						}
						else
						{
							ImGui::SameLine();
							ImGui::Text("%.2f", entityRot.z);
						}
					}

					if (ImGui::TreeNodeEx("Scale", NULL, "Scale"))
					{
						if (!b_2DcoordinatesOnly)
						{
							if (lockScaleRatio)
							{
								ImGui::Text("X: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##xSca", &entitySca.x, 1.f, NULL, NULL, "%.2f"))
								{
									Data[i].scale.x = entitySca.x;
									Data[i].scale.y = entitySca.x;
								}
								ImGui::Text("Y: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##ySca", &entitySca.x, 1.f, NULL, NULL, "%.2f"))
								{
									Data[i].scale.x = entitySca.x;
									Data[i].scale.y = entitySca.x;
								}
							}
							else
							{
								ImGui::Text("X: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##xSca", &entitySca.x, 1.f, NULL, NULL, "%.2f")) { Data[i].scale.x = entitySca.x; }
								ImGui::Text("Y: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##ySca", &entitySca.y, 1.f, NULL, NULL, "%.2f")) { Data[i].scale.y = entitySca.y; }
							}
							ImGui::Text("Z: ");
							ImGui::SameLine();
							if (ImGui::DragFloat("##zSca", &entitySca.z, 1.f, NULL, NULL, "%.2f")) { Data[i].scale.z = entitySca.z; }
							ImGui::SameLine();
							ImGui::Text("Lock ratio: ");
							ImGui::SameLine();
							if (ImGui::Checkbox("##lockScaleRatio", &lockScaleRatio)) { Data[i].lockScaleRatio = lockScaleRatio; }
						}
						else
						{
							if (lockScaleRatio)
							{
								ImGui::Text("X: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##xSca", &entitySca.x, 1.f, NULL, NULL, "%.2f"))
								{
									Data[i].scale.x = entitySca.x;
									Data[i].scale.y = entitySca.x;
								}
								ImGui::Text("Y: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##ySca", &entitySca.x, 1.f, NULL, NULL, "%.2f"))
								{
									Data[i].scale.x = entitySca.x;
									Data[i].scale.y = entitySca.x;
								}
							}
							else
							{
								ImGui::Text("X: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##xSca", &entitySca.x, 1.f, NULL, NULL, "%.2f")) { Data[i].scale.x = entitySca.x; }
								ImGui::Text("Y: ");
								ImGui::SameLine();
								if (ImGui::DragFloat("##ySca", &entitySca.y, 1.f, NULL, NULL, "%.2f")) { Data[i].scale.y = entitySca.y; }
							}
							ImGui::SameLine();
							ImGui::Text("Lock ratio: ");
							ImGui::SameLine();
							if (ImGui::Checkbox("##lockScaleRatio", &lockScaleRatio)) { Data[i].lockScaleRatio = lockScaleRatio; }
						}

						ImGui::TreePop();
						ImGui::Spacing();
						ImGui::Separator();
					}
					else
					{
						if (!b_2DcoordinatesOnly)
						{
							ImGui::SameLine();
							ImGui::Text("X: %.2f | ", entitySca.x);
							ImGui::SameLine();
							ImGui::Text("Y: %.2f | ", entitySca.y);
							ImGui::SameLine();
							ImGui::Text("Z: %.2f", entitySca.z);
						}
						else
						{
							ImGui::SameLine();
							ImGui::Text("X: %.2f | ", entitySca.x);
							ImGui::SameLine();
							ImGui::Text("Y: %.2f", entitySca.y);
						}
					}

					ImGui::Separator();
					ImGui::Spacing();
					ImGui::Text("Other Options");
					ImGui::Spacing();
					ImGui::Separator();

					if (ImGui::TreeNodeEx("Texture", NULL, "Texture"))
					{
						if (ImGui::SmallButton("Browse")) {}
						ImGui::SameLine();
						ImGui::Text("%s", texPath);

						ImGui::TreePop();
						ImGui::Separator();
					}

					ImGui::Spacing();
					if (ImGui::TreeNodeEx("Other", NULL, "Other"))
					{
						ImGui::Text("Movement Speed: ");
						ImGui::SameLine();
						if (ImGui::DragFloat("##movSpeed", &movSpeed, 1.f, NULL, NULL, "%.2f")) { Data[i].MovementSpeed = movSpeed; }
						ImGui::Text("Generate Overlap: ");
						ImGui::SameLine();
						if (ImGui::Checkbox("##GenOverlap", &genOverlap)) { Data[i].GeneratePhysOverlap = genOverlap; }

						ImGui::TreePop();
						ImGui::Separator();
					}
					ImGui::Spacing();
					ImGui::Separator();

					ImGui::TreePop();
				}

				ImGui::PopID();

				Data[i].model.UpdateMeshTransform(entityPos, entityRot, entitySca);
				m_scene->Entities_Data = Data;


			}

			ImGui::TreePop();
		}
	}
}