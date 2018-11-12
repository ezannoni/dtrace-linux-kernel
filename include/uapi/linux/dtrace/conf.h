/*
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * http://oss.oracle.com/licenses/upl.
 *
 * Copyright (c) 2009, 2018, Oracle and/or its affiliates. All rights reserved.
 */

/*
 * Note: The contents of this file are private to the implementation of the
 * DTrace subsystem and are subject to change at any time without notice.
 */

#ifndef _LINUX_DTRACE_CONF_H
#define _LINUX_DTRACE_CONF_H

#include <linux/dtrace/universal.h>
#include <linux/dtrace/conf_defines.h>

/*
 * User-level may need to understand some elements of the kernel DTrace
 * configuration in order to generate correct BPF.  This information is
 * conveyed via the dtrace_conf structure.
 *
 * The BPF "version" is a DTrace-internal integer (DBPF_VERSION) incremented
 * whenever new helpers are added that DTrace userspace makes use of.
 */
typedef struct dtrace_conf {
	uint_t dtc_bpfversion;			/* supported BPF "version" */
	uint_t dtc_bpfnregs;			/* # of bpf registers */
	uint_t dtc_bpfclobregs;			/* # of call-clobbered registers */
	uint_t dtc_ctfmodel;			/* CTF data model */
	/* Deviation from Solaris...  Used to just be 8 padding entries. */
	uint_t dtc_maxbufs;			/* max # of buffers */
	uint_t dtc_pad[7];			/* reserved for future use */
} dtrace_conf_t;

#endif /* _LINUX_DTRACE_CONF_H */
