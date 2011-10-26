#define PURPLE_PLUGINS

#include <gtk/gtk.h>
#include <glib.h>
#include <gdk/gdkkeysyms.h>

#include "gtkimhtml.h"
#include "notify.h"
#include "plugin.h"
#include "version.h"

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
