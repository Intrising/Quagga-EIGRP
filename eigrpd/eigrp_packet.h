/*
 * EIGRP Sending and Receiving EIGRP Packets.
 * Copyright (C) 2013-2014
 * Authors:
 * Jan Janovic
 * Matej Perina
 * Peter Orsag
 * Peter Paluch
 *
 * This file is part of GNU Zebra.
 *
 * GNU Zebra is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * GNU Zebra is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Zebra; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef _ZEBRA_EIGRP_PACKET_H
#define _ZEBRA_EIGRP_PACKET_H

/*Prototypes*/
extern int eigrp_read (struct thread *);
extern struct eigrp_fifo *eigrp_fifo_new (void);
extern struct eigrp_packet *eigrp_packet_new (size_t);
extern void eigrp_hello_send (struct eigrp_interface *);
extern void eigrp_update_send (struct eigrp_interface *, struct eigrp_prefix_entry *);
extern struct eigrp_packet *eigrp_fifo_head (struct eigrp_fifo *);
extern struct eigrp_packet *eigrp_fifo_tail (struct eigrp_fifo *);
extern void eigrp_packet_delete (struct eigrp_interface *);
extern struct eigrp_packet *eigrp_fifo_pop (struct eigrp_fifo *);
extern void eigrp_packet_free (struct eigrp_packet *);
extern void eigrp_fifo_free (struct eigrp_fifo *);
extern void eigrp_fifo_reset (struct eigrp_fifo *);
extern void eigrp_ack_send(struct eigrp_neighbor *);
extern void eigrp_send_init_update (struct eigrp_neighbor *);
extern void eigrp_send_EOT_update(struct eigrp_neighbor *);
extern void eigrp_send_packet_reliably(struct eigrp_neighbor *);
extern void eigrp_send_reply(struct eigrp_neighbor *, struct eigrp_neighbor_entry *);
extern void eigrp_send_query(struct eigrp_neighbor *, struct eigrp_neighbor_entry *);
extern void eigrp_update_send_all (struct eigrp_prefix_entry *, struct eigrp_interface *);
extern void eigrp_query_send_all (struct eigrp_neighbor_entry *);
extern struct eigrp_packet *eigrp_packet_duplicate(struct eigrp_packet *,
                                                   struct eigrp_neighbor *);
extern struct TLV_IPv4_Internal_type *eigrp_read_ipv4_tlv(struct stream *);
extern u_int16_t eigrp_add_internalTLV_to_stream(struct stream *, struct eigrp_neighbor_entry *);


extern int eigrp_unack_packet_retrans(struct thread *);
extern int eigrp_unack_multicast_packet_retrans(struct thread *);

extern struct eigrp_packet *eigrp_fifo_pop_tail (struct eigrp_fifo *);

#endif /* _ZEBRA_EIGRP_PACKET_H */
