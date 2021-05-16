#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>


typedef struct _CustomData {
  GstElement *playbin;  
  
  GtkWidget *slider;              /* Slider widget to keep track of current position */
  GtkWidget *streams_list;        /* Text widget to display info about the streams */
  gulong slider_update_signal_id;
 
  GstState state;
 
  gboolean playing;      
  gboolean terminate;    
  gboolean seek_enabled; 
  gboolean seek_done;    
  gint64 duration;       
} CustomData;


void create_ui (CustomData *data);

void realize_cb (GtkWidget *widget, CustomData *data);

//static void play_cb (CustomData *data);

//static void pause_cb (CustomData *data);

void stop_cb (GtkButton *button, CustomData *data); 

void delete_event_cb (GtkWidget *widget, GdkEvent *event, CustomData *data);

gboolean draw_cb (GtkWidget *widget, cairo_t *cr, CustomData *data);

//static void slider_cb (GtkRange *range, CustomData *data);

