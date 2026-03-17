
#ifndef SQSGEN_TEMPLATES_TEMPLATES_H
#define SQSGEN_TEMPLATES_TEMPLATES_H

#include <nlohmann/json.hpp>

namespace sqsgen::templates {

    struct config_template_author {
        std::optional<std::string> name;
        std::optional<std::string> surname;
        std::optional<std::string> email;
        std::optional<std::string> affiliation;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(config_template_author, name, surname, email, affiliation);
    };

    struct config_template {
        std::string name;
        std::string description;
        std::vector<std::string> tags;
        std::optional<std::string> doi;
        std::vector<config_template_author> authors;
        nlohmann::json config;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(config_template, name, description, tags, authors, config);
    };

    namespace detail {
        static const std::map<std::string, config_template> templates = {
         {"re-w.first", 
config_template {
"re-w.first",
"Fully miscible Re-W at 50/50 compostition in a bcc structure. Only 1st nearest neighbor interactions are considered.",
std::vector<std::string>{"Cubic", "bcc", "Re", "W", "interact", "54 at."},
std::nullopt,
std::vector{
config_template_author{
    "Dominik",
    "Gehringer",
    "None",
   std::nullopt
}},
nlohmann::json::parse(R"({"structure": {"lattice": [[3.165, 0.0, 0.0], [0.0, 3.165, 0.0], [0.0, 0.0, 3.165]], "coords": [[0.0, 0.0, 0.0], [0.5, 0.5, 0.5]], "species": ["W", "Re"], "supercell": [3, 3, 3]}, "iterations": 50000000, "shell_weights": {"1": 1.0}, "composition": {"W": 27, "Re": 27}, "max_results_per_objective": 10})")
}
},
{"ti-al-b-n", 
config_template {
"ti-al-b-n",
"Cubic B2 structure with Ti and N. Optimization is carried out on each sublattice independently. Ti is populated (TiAl) and optimized towards ordering. The non-metal sublattice (N) is populated with N and B and optimized towards clustering.",
std::vector<std::string>{"Cubic", "B1", "Ti", "N", "split", "216 at."},
std::nullopt,
std::vector{
config_template_author{
    "Dominik",
    "Gehringer",
    "None",
   std::nullopt
}},
nlohmann::json::parse(R"({"iterations": 1000000000, "sublattice_mode": "split", "structure": {"supercell": [3, 3, 3], "species": ["Ti", "Ti", "Ti", "Ti", "N", "N", "N", "N"], "lattice": [[4.253534, 0.0, 0.0], [0.0, 4.253534, 0.0], [0.0, 0.0, 4.253534]], "coords": [[0.5, 0.0, 0.0], [0.5, 0.5, 0.5], [0.0, 0.0, 0.5], [0.0, 0.5, 0.0], [0.0, 0.0, 0.0], [0.0, 0.5, 0.5], [0.5, 0.0, 0.5], [0.5, 0.5, 0.0]]}, "composition": [{"sites": "Ti", "Ti": 54, "Al": 54}, {"sites": "N", "N": 54, "B": 54}], "target_objective": [-1, 1]})")
}
}
        };
    } // namespace detail

  inline const std::map<std::string, config_template>& templates() {
    return detail::templates;
  }

} // namespace sqsgen::templates

#endif // SQSGEN_TEMPLATES_TEMPLATES_H
