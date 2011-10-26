#define PURPLE_PLUGINS

#include <gtk/gtk.h>
#include <glib.h>
#include <gdk/gdkkeysyms.h>
#include <plugin.h>
#include <version.h>

/* From gtkimhtml.h */
typedef enum {
        GTK_IMHTML_BOLD =       1 << 0,
        GTK_IMHTML_ITALIC =     1 << 1,
        GTK_IMHTML_UNDERLINE =  1 << 2,
        GTK_IMHTML_GROW =       1 << 3,
        GTK_IMHTML_SHRINK =     1 << 4,
        GTK_IMHTML_FACE =       1 << 5,
        GTK_IMHTML_FORECOLOR =  1 << 6,
        GTK_IMHTML_BACKCOLOR =  1 << 7,
        GTK_IMHTML_BACKGROUND = 1 << 8,
        GTK_IMHTML_LINK =       1 << 9,
        GTK_IMHTML_IMAGE =      1 << 10,
        GTK_IMHTML_SMILEY =     1 << 11,
        GTK_IMHTML_LINKDESC =   1 << 12,
        GTK_IMHTML_STRIKE =     1 << 13,
        /** Show custom smileys when appropriate. @since 2.5.0 */
        GTK_IMHTML_CUSTOM_SMILEY = 1 << 14,
        GTK_IMHTML_ALL =       -1
} GtkIMHtmlButtons;

static gboolean
plugin_load(PurplePlugin *plugin) {
    GtkTextViewClass *parent_class = g_type_class_ref(GTK_TYPE_TEXT_VIEW);
    GtkBindingSet *binding_set = gtk_binding_set_by_class (parent_class);

    gtk_binding_entry_add_signal (binding_set, GDK_s, GDK_CONTROL_MASK, "format_function_toggle", 1, G_TYPE_INT, GTK_IMHTML_STRIKE);

    return TRUE;
}

static PurplePluginInfo info = {
    PURPLE_PLUGIN_MAGIC,
    PURPLE_MAJOR_VERSION,
    PURPLE_MINOR_VERSION,
    PURPLE_PLUGIN_STANDARD,
    NULL,
    0,
    NULL,
    PURPLE_PRIORITY_DEFAULT,

    "gtk-niyafox-quickstrike",
    "QuickStrike",
    "1.0",

    "Adds key binding for strikethrough",          
    "Adds a key binding for strikethrough, similar to bold, italics, and underline.",
    "Nicole Borrelli <niya@isisview.org>",
    "http://cutely.co/",     
    
    plugin_load,                   
    NULL,                          
    NULL,                          
                                   
    NULL,                          
    NULL,                          
    NULL,                        
    NULL,                   
    NULL,                          
    NULL,                          
    NULL,                          
    NULL                           
};                               
    
static void                        
init_plugin(PurplePlugin *plugin)
{
}

PURPLE_INIT_PLUGIN(hello_world, init_plugin, info)
