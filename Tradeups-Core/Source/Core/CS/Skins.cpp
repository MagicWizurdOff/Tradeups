#include "Skins.h"

using json = nlohmann::json;


Skins::Skins(std::string fileName)
{
    this->skins = {};
    loadSkins(fileName);
}

void Skins::loadSkins(std::string fileName) {

    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Chyba pøi otevírání souboru!" << std::endl;
        return;
    }

    json jsonData;
    file >> jsonData;

    
    for (int i = 0; i < jsonData.size(); i++) {
        try {
            std::cout << "Parsing: " << i << std::endl;

            // Kontrola a pøiøazení pro "id"
            std::string id = "";  // Defaultní hodnota pro "id"
            if (jsonData[i].contains("id") && jsonData[i]["id"].is_string()) {
                id = jsonData[i]["id"];
            }

            // Kontrola a pøiøazení pro "name"
            std::string name = "";
            if (jsonData[i].contains("name") && jsonData[i]["name"].is_string()) {
                name = jsonData[i]["name"];
            }

            // Kontrola a pøiøazení pro "description"
            std::string description = "";
            if (jsonData[i].contains("description") && jsonData[i]["description"].is_string()) {
                description = jsonData[i]["description"];
            }

            // Kontrola a pøiøazení pro "weapon"
            Weapon weapon("", 0, "");  // Defaultní prázdný konstruktér
            if (jsonData[i].contains("weapon") && jsonData[i]["weapon"].is_object()) {
                std::string weapon_id = "";
                if (jsonData[i]["weapon"].contains("id") && jsonData[i]["weapon"]["id"].is_string()) {
                    weapon_id = jsonData[i]["weapon"]["id"];
                }
                int weapon_weapon_id = 0;
                if (jsonData[i]["weapon"].contains("weapon_id") && jsonData[i]["weapon"]["weapon_id"].is_number()) {
                    weapon_weapon_id = jsonData[i]["weapon"]["weapon_id"];
                }
                std::string weapon_name = "";
                if (jsonData[i]["weapon"].contains("name") && jsonData[i]["weapon"]["name"].is_string()) {
                    weapon_name = jsonData[i]["weapon"]["name"];
                }
                weapon = Weapon(weapon_id, weapon_weapon_id, weapon_name);  // Inicializace s daty
            }

            // Kontrola a pøiøazení pro "category"
            Category category("", "");  // Defaultní prázdný konstruktér
            if (jsonData[i].contains("category") && jsonData[i]["category"].is_object()) {
                std::string category_id = "";
                if (jsonData[i]["category"].contains("id") && jsonData[i]["category"]["id"].is_string()) {
                    category_id = jsonData[i]["category"]["id"];
                }
                std::string category_name = "";
                if (jsonData[i]["category"].contains("name") && jsonData[i]["category"]["name"].is_string()) {
                    category_name = jsonData[i]["category"]["name"];
                }
                category = Category(category_id, category_name);  // Inicializace s daty
            }

            // Kontrola a pøiøazení pro "pattern"
            Pattern pattern("", "");  // Defaultní prázdný konstruktér
            if (jsonData[i].contains("pattern") && jsonData[i]["pattern"].is_object()) {
                std::string pattern_id = "";
                if (jsonData[i]["pattern"].contains("id") && jsonData[i]["pattern"]["id"].is_string()) {
                    pattern_id = jsonData[i]["pattern"]["id"];
                }
                std::string pattern_name = "";
                if (jsonData[i]["pattern"].contains("name") && jsonData[i]["pattern"]["name"].is_string()) {
                    pattern_name = jsonData[i]["pattern"]["name"];
                }
                pattern = Pattern(pattern_id, pattern_name);  // Inicializace s daty
            }

            // Kontrola a pøiøazení pro "max_float"
            float max_float = 0.0f;  // Defaultní hodnota
            if (jsonData[i].contains("max_float") && jsonData[i]["max_float"].is_number()) {
                max_float = jsonData[i]["max_float"];
            }

            // Kontrola a pøiøazení pro "min_float"
            float min_float = 0.0f;  // Defaultní hodnota
            if (jsonData[i].contains("min_float") && jsonData[i]["min_float"].is_number()) {
                min_float = jsonData[i]["min_float"];
            }

            // Kontrola a pøiøazení pro "rarity"
            Rarity rarity("", "", "");  // Defaultní prázdný konstruktér
            if (jsonData[i].contains("rarity") && jsonData[i]["rarity"].is_object()) {
                std::string rarity_id = "";
                if (jsonData[i]["rarity"].contains("id") && jsonData[i]["rarity"]["id"].is_string()) {
                    rarity_id = jsonData[i]["rarity"]["id"];
                }
                std::string rarity_name = "";
                if (jsonData[i]["rarity"].contains("name") && jsonData[i]["rarity"]["name"].is_string()) {
                    rarity_name = jsonData[i]["rarity"]["name"];
                }
                std::string rarity_color = "";
                if (jsonData[i]["rarity"].contains("color") && jsonData[i]["rarity"]["color"].is_string()) {
                    rarity_color = jsonData[i]["rarity"]["color"];
                }
                rarity = Rarity(rarity_id, rarity_name, rarity_color);  // Inicializace s daty
            }

            // Kontrola a pøiøazení pro "stattrack"
            bool stattrack = false;  // Defaultní hodnota
            if (jsonData[i].contains("stattrack") && jsonData[i]["stattrack"].is_boolean()) {
                stattrack = jsonData[i]["stattrack"];
            }

            // Kontrola a pøiøazení pro "souvenier"
            bool souvenier = false;  // Defaultní hodnota
            if (jsonData[i].contains("souvenier") && jsonData[i]["souvenier"].is_boolean()) {
                souvenier = jsonData[i]["souvenier"];
            }

            // Kontrola a pøiøazení pro "paint_index"
            std::string paint_index = "";
            if (jsonData[i].contains("paint_index") && jsonData[i]["paint_index"].is_string()) {
                paint_index = jsonData[i]["paint_index"];
            }

            // Kontrola a pøiøazení pro "wears"
            std::vector<Wear> wears;
            if (jsonData[i].contains("wears") && jsonData[i]["wears"].is_array()) {
                for (int j = 0; j < jsonData[i]["wears"].size(); j++) {
                    std::string wear_id = "";
                    std::string wear_name = "";
                    if (jsonData[i]["wears"][j].contains("id") && jsonData[i]["wears"][j]["id"].is_string()) {
                        wear_id = jsonData[i]["wears"][j]["id"];
                    }
                    if (jsonData[i]["wears"][j].contains("name") && jsonData[i]["wears"][j]["name"].is_string()) {
                        wear_name = jsonData[i]["wears"][j]["name"];
                    }
                    wears.push_back(Wear(wear_id, wear_name));
                }
            }

            // Kontrola a pøiøazení pro "collections"
            std::vector<Collection> collections;
            if (jsonData[i].contains("collections") && jsonData[i]["collections"].is_array()) {
                for (int j = 0; j < jsonData[i]["collections"].size(); j++) {
                    std::string collection_id = "";
                    std::string collection_name = "";
                    std::string collection_image = "";
                    if (jsonData[i]["collections"][j].contains("id") && jsonData[i]["collections"][j]["id"].is_string()) {
                        collection_id = jsonData[i]["collections"][j]["id"];
                    }
                    if (jsonData[i]["collections"][j].contains("name") && jsonData[i]["collections"][j]["name"].is_string()) {
                        collection_name = jsonData[i]["collections"][j]["name"];
                    }
                    if (jsonData[i]["collections"][j].contains("image") && jsonData[i]["collections"][j]["image"].is_string()) {
                        collection_image = jsonData[i]["collections"][j]["image"];
                    }
                    collections.push_back(Collection(collection_id, collection_name, collection_image));
                }
            }

            // Kontrola a pøiøazení pro "creates"
            std::vector<Crate> creates;
            if (jsonData[i].contains("creates") && jsonData[i]["creates"].is_array()) {
                for (int j = 0; j < jsonData[i]["creates"].size(); j++) {
                    std::string create_id = "";
                    std::string create_name = "";
                    std::string create_image = "";
                    if (jsonData[i]["creates"][j].contains("id") && jsonData[i]["creates"][j]["id"].is_string()) {
                        create_id = jsonData[i]["creates"][j]["id"];
                    }
                    if (jsonData[i]["creates"][j].contains("name") && jsonData[i]["creates"][j]["name"].is_string()) {
                        create_name = jsonData[i]["creates"][j]["name"];
                    }
                    if (jsonData[i]["creates"][j].contains("image") && jsonData[i]["creates"][j]["image"].is_string()) {
                        create_image = jsonData[i]["creates"][j]["image"];
                    }
                    creates.push_back(Crate(create_id, create_name, create_image));
                }
            }

            Team team("", "");  // Defaultní prázdný konstruktér
            if (jsonData[i].contains("team") && jsonData[i]["team"].is_object()) {
                std::string team_id = "";
                if (jsonData[i]["team"].contains("id") && jsonData[i]["rarity"]["id"].is_string()) {
                    team_id = jsonData[i]["team"]["id"];
                }
                std::string team_name = "";
                if (jsonData[i]["team"].contains("name") && jsonData[i]["rarity"]["name"].is_string()) {
                    team_name = jsonData[i]["team"]["name"];
                }

                team = Team(team_id, team_name);  // Inicializace s daty
            }


            // Kontrola a pøiøazení pro "stattrack"
            bool legacy_model = false;  // Defaultní hodnota
            if (jsonData[i].contains("legacy_model") && jsonData[i]["legacy_model"].is_boolean()) {
                legacy_model = jsonData[i]["legacy_model"];
            }

            std::string image = "";
            if (jsonData[i].contains("image") && jsonData[i]["image"].is_string()) {
                image = jsonData[i]["image"];
            }

            Skin skin(id,
                name,
                description,
                weapon,
                category,
                pattern,
                max_float,
                min_float,
                rarity,
                stattrack,
                souvenier,
                paint_index,
                wears,
                collections,
                creates,
                team,
                legacy_model,
                image);

            this->skins.push_back(skin);
            //logSkin(skin);

        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing item " << i << ": " << e.what() << std::endl;
        }
        catch (const nlohmann::json::exception& e) {
            std::cerr << "JSON error: " << e.what() << std::endl;
        }
    }
}





void Skins::logSkin(Skin skin)
{
    std::cout << "Skin Attributes:" << std::endl;
    std::cout << "ID: " << skin.getId() << std::endl;
    std::cout << "Name: " << skin.getName() << std::endl;
    std::cout << "Description: " << skin.getDescription() << std::endl;

    // Weapon details
    Weapon weapon = skin.getWeapon();
    std::cout << "Weapon ID: " << weapon.getId() << std::endl;
    std::cout << "Weapon Weapon ID: " << weapon.getWeaponId() << std::endl;
    std::cout << "Weapon Name: " << weapon.getName() << std::endl;

    // Category details
    Category category = skin.getCategory();
    std::cout << "Category ID: " << category.getId() << std::endl;
    std::cout << "Category Name: " << category.getName() << std::endl;

    // Pattern details
    Pattern pattern = skin.getPattern();
    std::cout << "Pattern ID: " << pattern.getId() << std::endl;
    std::cout << "Pattern Name: " << pattern.getName() << std::endl;

    std::cout << "Max Float: " << skin.getMaxFloat() << std::endl;
    std::cout << "Min Float: " << skin.getMinFloat() << std::endl;

    // Rarity details
    Rarity rarity = skin.getRarity();
    std::cout << "Rarity ID: " << rarity.getId() << std::endl;
    std::cout << "Rarity Name: " << rarity.getName() << std::endl;
    std::cout << "Rarity Color: " << rarity.getColor() << std::endl;

    std::cout << "Stattrack: " << (skin.hasStattrack() ? "Yes" : "No") << std::endl;
    std::cout << "Souvenier: " << (skin.isSouvenier() ? "Yes" : "No") << std::endl;
    std::cout << "Paint Index: " << skin.getPaintIndex() << std::endl;

    // Wears details
    std::vector<Wear> wears = skin.getWears();
    std::cout << "Wears:" << std::endl;
    for (const Wear& wear : wears) {
        std::cout << "  Wear ID: " << wear.getId() << ", Name: " << wear.getName() << std::endl;
    }

    // Collections details
    std::vector<Collection> collections = skin.getCollections();
    std::cout << "Collections:" << std::endl;
    for (const Collection& collection : collections) {
        std::cout << "  Collection ID: " << collection.getId()
            << ", Name: " << collection.getName()
            << ", Image: " << collection.getImage() << std::endl;
    }

    // Creates details
    std::vector<Crate> creates = skin.getCreates();
    std::cout << "Creates:" << std::endl;
    for (const Crate& create : creates) {
        std::cout << "  Create ID: " << create.getId()
            << ", Name: " << create.getName()
            << ", Image: " << create.getImage() << std::endl;
    }

    std::cout << "\n\n\n|------------------------------------------|\n\n\n" << std::endl;
}
