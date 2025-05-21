#include "Skin.h"


// Konstruktor
Skin::Skin(std::string id, std::string name, std::string description, Weapon weapon, Category category, Pattern pattern,
    float min_float, float max_float, Rarity rarity, bool stattrack, bool souvenier, std::string paint_index,
    std::vector<Wear> wears, std::vector<Collection> collections, std::vector<Crate> creates, Team team,
    bool legacy_model, std::string image)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->weapon = weapon;
    this->category = category;
    this->pattern = pattern;
    this->min_float = min_float;
    this->max_float = max_float;
    this->rarity = rarity;
    this->stattrack = stattrack;
    this->souvenier = souvenier;
    this->paint_index = paint_index;
    this->wears = wears;
    this->collections = collections;
    this->creates = creates;
    this->team = team;
    this->legacy_model = legacy_model;
    this->image = image;
}


Skin::Skin() : id(""), name(""), description(""), weapon(Weapon()), category(Category()), pattern(Pattern()),
min_float(0.0f), max_float(0.0f), rarity(Rarity()), stattrack(false), souvenier(false),
paint_index(""), wears(std::vector<Wear>()), collections(std::vector<Collection>()),
creates(std::vector<Crate>()), team(Team()), legacy_model(false), image("") {}


std::string Skin::getId() const { return id; }
std::string Skin::getName() const { return name; }
std::string Skin::getDescription() const { return description; }
Weapon Skin::getWeapon() const { return weapon; }
Category Skin::getCategory() const { return category; }
Pattern Skin::getPattern() const { return pattern; }
float Skin::getMinFloat() const { return min_float; }
float Skin::getMaxFloat() const { return max_float; }
Rarity Skin::getRarity() const { return rarity; }
bool Skin::hasStattrack() const { return stattrack; }
bool Skin::isSouvenier() const { return souvenier; }
std::string Skin::getPaintIndex() const { return paint_index; }
std::vector<Wear> Skin::getWears() const { return wears; }
std::vector<Collection> Skin::getCollections() const { return collections; }
std::vector<Crate> Skin::getCreates() const { return creates; }
Team Skin::getTeam() const { return team; }
bool Skin::hasLegacyModel() const { return legacy_model; }
std::string Skin::getImage() const { return image; }

void Skin::setId(std::string id) { this->id = id; }
void Skin::setName(const std::string& name) { this->name = name; }
void Skin::setDescription(const std::string& description) { this->description = description; }
void Skin::setWeapon(const Weapon& weapon) { this->weapon = weapon; }
void Skin::setCategory(const Category& category) { this->category = category; }
void Skin::setPattern(const Pattern& pattern) { this->pattern = pattern; }
void Skin::setMinFloat(float min_float) { this->min_float = min_float; }
void Skin::setMaxFloat(float max_float) { this->max_float = max_float; }
void Skin::setRarity(const Rarity& rarity) { this->rarity = rarity; }
void Skin::setStattrack(bool stattrack) { this->stattrack = stattrack; }
void Skin::setSouvenier(bool souvenier) { this->souvenier = souvenier; }
void Skin::setPaintIndex(const std::string& paint_index) { this->paint_index = paint_index; }
void Skin::setWears(const std::vector<Wear>& wears) { this->wears = wears; }
void Skin::setCollections(const std::vector<Collection>& collections) { this->collections = collections; }
void Skin::setCreates(const std::vector<Crate>& creates) { this->creates = creates; }
void Skin::setTeam(const Team& team) { this->team = team; }
void Skin::setLegacyModel(bool legacy_model) { this->legacy_model = legacy_model; }
void Skin::setImage(const std::string& image) { this->image = image; }

bool Skin::operator==(const Skin& rhs) const
{
    bool matchingWears = true;
    if (this->wears.size() == rhs.getWears().size()) {
        for (int i = 0; i < this->wears.size(); i++) {
            if (this->wears.at(i) != rhs.getWears().at(i))
                matchingWears = false;
        }
    }

    bool matchingCollections = true;
    if (this->collections.size() == rhs.getCollections().size()) {
        for (int i = 0; i < this->collections.size(); i++) {
            if (this->collections.at(i) != rhs.getCollections().at(i))
                matchingCollections = false;
        }
    }

    bool matchingCreates = true;
    if (this->creates.size() == rhs.getCreates().size()) {
        for (int i = 0; i < this->creates.size(); i++) {
            if (this->creates.at(i) != rhs.getCreates().at(i))
                matchingCreates = false;
        }
    }

    return this->id == rhs.getId() &&
        this->name == rhs.getName() &&
        this->description == rhs.getDescription() &&
        this->weapon == rhs.getWeapon() &&
        this->category == rhs.getCategory() &&
        this->pattern == rhs.getPattern() &&
        this->min_float == rhs.getMinFloat() &&
        this->max_float == rhs.getMaxFloat() &&
        this->rarity == rhs.getRarity() &&
        this->stattrack == rhs.hasStattrack() &&
        this->souvenier == rhs.isSouvenier() &&
        this->paint_index == rhs.getPaintIndex() &&
        matchingCollections && matchingCollections &&
        matchingWears &&
        this->team == rhs.getTeam() &&
        this->legacy_model == rhs.hasLegacyModel() &&
        this->image == rhs.getImage();
        
}