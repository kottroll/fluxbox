#include "IconbarTheme.hh"
#include "FbTk/App.hh"

IconbarTheme::IconbarTheme(int screen_num, 
                           const std::string &name,
                           const std::string &altname):
    FbTk::Theme(screen_num),
    m_focused_texture(*this, name + ".focused", altname + ".Focused"),
    m_unfocused_texture(*this, name + ".unfocused", altname + ".Unfocused"),
    m_empty_texture(*this, name + ".empty", altname + ".Empty"),
    m_focused_border(*this, name + ".focused", altname + ".Focused"),
    m_unfocused_border(*this, name + ".unfocused", altname + ".Unfocused"),
    m_border(*this, name, altname),
    m_focused_text(*this, name + ".focused", altname + ".Focused"),
    m_unfocused_text(*this, name + ".unfocused", altname + ".Unfocused") {

    FbTk::ThemeManager::instance().loadTheme(*this);

}
IconbarTheme::~IconbarTheme() {

}


void IconbarTheme::reconfigTheme() {
    m_focused_text.update();
    m_unfocused_text.update();
}

void IconbarTheme::setAntialias(bool value) {
    m_focused_text.setAntialias(value);
    m_unfocused_text.setAntialias(value);
}

