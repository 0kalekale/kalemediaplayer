#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>
#include <string.h>

#include "youtube_dl.h"
struct av_url
*get_url(char url[])
{
    setenv("PYTHONPATH",".",1);
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    struct av_url *master =  malloc (2048);
    //PyObject *audio_url, *video_url;
	
    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("PyKmp");
   
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "get_url_video");
        Py_DECREF(pModule);	
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = Py_BuildValue("(s)", url);
	    printf("after building args\n"); 
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                PyObject *pyvideo;
		PyObject *pyaudio;
		PyObject *byvideo;
		PyObject *byaudio;

		pyvideo = PyTuple_GetItem(pValue, 0);
		pyaudio = PyTuple_GetItem(pValue, 1);
		Py_DECREF(pValue);
                if (!PyUnicode_Check(pyvideo)) { printf("pyvideo is not unicode\n"); exit(1);}
 		//printf("after PyTuple_getItem\n");
		//if (pyvideo == NULL) { printf("nullptr in pyvideo\n"); exit(1);}
		byvideo = PyUnicode_AsUTF8String(pyvideo);
		byaudio = PyUnicode_AsUTF8String(pyaudio);
     		//printf("after PyBytes_FromObject\n");
		Py_DECREF(pyvideo);
		Py_DECREF(pyaudio);
		//printf("after freeing pyvideo and audio\n");
		//if (byvideo == NULL) { printf("nullptr in byvideo\n"); exit(1);}
		//else {printf("made it here");}
		strcpy(master->video, PyBytes_AsString(byvideo));
		//char *final_video = PyBytes_AsString(byvideo);
		Py_DECREF(byvideo);
		//char *final_audio = PyBytes_AsString(byaudio);
		strcpy(master->audio, PyBytes_AsString(byaudio));
		Py_DECREF(byaudio);
		
		//Py_DECREF(pValue);
		//printf("before strcat");
		//rcat(vid_ref, final_video);
		//rcat(aud_ref, final_audio);
                return master;
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return master;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load");
        return master;
    }
    if (Py_FinalizeEx() < 0) {
        return master;
    }
    return master;
}


