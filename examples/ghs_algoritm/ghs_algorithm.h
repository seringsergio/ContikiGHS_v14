#ifndef GHS_ALGORITHM_H
#define GHS_ALGORITHM_H

/*------------------------------------------------------------------- */
/*----------- INCLUDES ------------------------------------------------ */
/*------------------------------------------------------------------- */

#include "contiki.h"
#include "lib/list.h"
#include "cfs/cfs.h" //para guardar archivos en el Contiki File System CFS

/*------------------------------------------------------------------- */
/*-----------DEBUG-------------------------------------------------*/
/*------------------------------------------------------------------- */

//Debug de prioridad 1. Quiere decir que siempre se imprime.
//ex: Mensajes para sacar graficas
//ex: Mensajes de Error
#define MY_DEBUG_1 1
#if MY_DEBUG_1
#include <stdio.h>
#define MY_DBG_1(...) printf(__VA_ARGS__)
#else
#define MY_DBG_1(...)
#endif

// Debug de prioridad 2. Quiere decir que a veces se imprime.
// ex: Codigo que estoy desarrollando y necesito hacer debug en ese momento
// En produccion los debug de prioridad 2 deben pasar a ser de prioridad 3
#define MY_DEBUG_2 0
#if MY_DEBUG_2
#include <stdio.h>
#define MY_DBG_2(...) printf(__VA_ARGS__)
#else
#define MY_DBG_2(...)
#endif

//Debug de prioridad 3. Quiere decir que nunca lo imprimo.
// ex: Codigo que ya esta desarrollado y ya se debugueo en el pasado.
#define MY_DEBUG_3 0
#if MY_DEBUG_3
#include <stdio.h>
#define MY_DBG_3(...) printf(__VA_ARGS__)
#else
#define MY_DBG_3(...)
#endif

/*------------------------------------------------------------------- */
/*-----------TYPEDEF-------------------------------------------------*/
/*------------------------------------------------------------------- */
//typedef struct wait s_wait;
typedef struct node node;
typedef struct edges edges;
/*------------------------------------------------------------------- */
/*-----------VARIABLES GLOBALES-------------------------------------------------*/
/*------------------------------------------------------------------- */

extern edges *e_list_head_g;
extern list_t report_list_g;
extern struct memb *report_memb_g;
extern node nd; //nd es node....n es neighbor

extern list_t co_list_out_g;
extern struct memb *co_mem_out_g;

extern list_t i_list_out_g;
extern struct memb *i_mem_out_g;

extern list_t t_list_out_g;
extern struct memb *t_mem_out_g;

extern list_t a_list_out_g;
extern struct memb *a_mem_out_g;

extern list_t rj_list_out_g;
extern struct memb *rj_mem_out_g;

extern list_t rp_list_out_g;
extern struct memb *rp_mem_out_g;

extern list_t rp_list_g;
extern struct memb *rp_mem_g;

extern list_t cr_list_out_g;
extern struct memb *cr_mem_out_g;

extern list_t info_list_out_g;
extern struct memb *info_mem_out_g;
/*------------------------------------------------------------------- */
/*-----------PROCESOS-------------------------------------------------*/
/*------------------------------------------------------------------- */
//Procesos generales
PROCESS_NAME(wait);

//Procesos de neighbor_discovery
PROCESS_NAME(n_broadcast_neighbor_discovery);
PROCESS_NAME(n_link_weight_worst_case);
PROCESS_NAME(master_neighbor_discovery);
PROCESS_NAME(master_co_i);

//Procesos de co i
PROCESS_NAME(send_message_co_i);
PROCESS_NAME(evaluar_msg_co);
PROCESS_NAME(evaluar_msg_i);
PROCESS_NAME(interface_GHS_and_Self_healing);
//Procesos de test ar
PROCESS_NAME(e_test);
PROCESS_NAME(send_message_test_ar);
PROCESS_NAME(evaluar_msg_test);
PROCESS_NAME(evaluar_msg_accept);
PROCESS_NAME(evaluar_msg_reject);

// master_report_ChaRoot
//PROCESS_NAME(master_report_ChaRoot);
PROCESS_NAME(send_message_report_ChaRoot);
PROCESS_NAME(evaluar_msg_rp);
PROCESS_NAME(e_LWOE);
PROCESS_NAME(evaluar_msg_cr);
PROCESS_NAME(evaluar_msg_info);

/*------------------------------------------------------------------- */
/*----------EVENTOS -------- -----------------------------------------*/
/*------------------------------------------------------------------- */

//Comunes a todos los procesos
extern process_event_t e_wait_stabilization;
//extern process_event_t e_infinite_wait;

//neighbor discovery
extern process_event_t e_discovery_broadcast;
extern process_event_t e_weight_worst;
extern process_event_t e_init_master_co_i;

// master co_i
    //estados
extern process_event_t e_found;
extern process_event_t e_find;
    //msg
extern process_event_t e_msg_connect;
extern process_event_t e_msg_initiate;

//test_ar

//estados
extern process_event_t e_evaluate_test;
extern process_event_t e_nd_lwoe; //Para saber si el nodo ya tiene su edge preferido
extern process_event_t e_ch_lwoe; // Para saber si los hijos ya reportaton el edge preferido

//msg
extern process_event_t e_msg_test;
extern process_event_t e_msg_reject;
extern process_event_t e_msg_accept;
extern process_event_t e_msg_ch_root;


// master_report_ChaRoot
    //Estados
//extern process_event_t e_init_master_report_ChaRoot;
    //msg
extern process_event_t e_msg_report;
//extern process_event_t e_msg_information;
extern process_event_t e_msg_ghs_end;

/*-------------------------------------------------------------------*/
/*---------------- Estructuras---------------------------------------*/
/*-------------------------------------------------------------------*/

/*struct wait
{
    uint8_t seconds;
    struct process *return_process;
};*/



#endif /* GHS_ALGORITHM_H */
