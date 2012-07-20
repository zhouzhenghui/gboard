#ifndef __GBD_LAYOUT_H__
#define __GBD_LAYOUT_H__

#include <glib-object.h>

#include "../interfaces/emitter.h"

#define GBD_LAYOUT_ERROR (gbd_layout_error_quark( ))

/// Return GType; Return Class
#define GBD_TYPE_LAYOUT (gbd_layout_get_type( ))

/// Check whether instance is derived; Cast it
#define GBD_IS_LAYOUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE( (obj),GBD_TYPE_LAYOUT ))
#define GBD_LAYOUT(obj) (G_TYPE_CHECK_INSTANCE_CAST( (obj),GBD_TYPE_LAYOUT,GbdLayout ))

/// Check whether class is derived; Cast it
#define GBD_IS_LAYOUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE( (klass),GBD_TYPE_LAYOUT ))
#define GBD_LAYOUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST( (klass),GBD_TYPE_LAYOUT,GbdLayoutClass ))

typedef enum {
	GBD_LAYOUT_ERROR_CODEPAGE, ///< Invalid UTF-8
	GBD_LAYOUT_ERROR_STRAY ///< Stray token in file
} GbdLayoutError;

typedef struct GbdLayoutPrivate GbdLayoutPrivate;

typedef struct {
	GObject parent;

	GbdLayoutPrivate* priv;
} GbdLayout;

typedef struct {
	GObjectClass parent;
} GbdLayoutClass;

gboolean gbd_layout_parse( GbdLayout*,gchar*,GError** );

GType gbd_layout_get_type( void );
GbdLayout* gbd_layout_new( gchar*,GbdEmitter* );

GQuark gbd_layout_error_quark( void ); 

#endif
