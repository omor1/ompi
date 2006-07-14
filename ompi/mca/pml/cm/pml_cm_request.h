/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2006 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2006 The Regents of the University of California.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef PML_CM_REQUEST_H
#define PML_CM_REQUEST_H

#include "ompi/mca/pml/base/pml_base_sendreq.h"
#include "ompi/mca/pml/base/pml_base_bsend.h"
#include "ompi/mca/pml/pml.h"
#include "ompi/mca/mtl/mtl.h"

/**
 * Type of request.
 */
typedef enum {
    MCA_PML_CM_REQUEST_NULL,
    MCA_PML_CM_REQUEST_SEND,
    MCA_PML_CM_REQUEST_RECV,
    MCA_PML_CM_REQUEST_IPROBE,
    MCA_PML_CM_REQUEST_PROBE
} mca_pml_cm_request_type_t;




/**
 *  Base type for PML CM P2P requests 
 */
struct mca_pml_cm_request_t { 
    ompi_request_t req_ompi;              /**< base request */
    volatile bool req_pml_complete;       /**< flag indicating if the pt-2-pt layer is done with this request */
    volatile bool req_free_called;        /**< flag indicating if the user has freed this request */
    mca_pml_cm_request_type_t req_pml_type;
    ompi_convertor_t req_convertor;       /**< always need the convertor */
};
typedef struct mca_pml_cm_request_t mca_pml_cm_request_t;
OMPI_DECLSPEC OBJ_CLASS_DECLARATION(mca_pml_cm_request_t);

#endif
