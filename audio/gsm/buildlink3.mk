# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:03:54 rillig Exp $

BUILDLINK_TREE+=	gsm

.if !defined(GSM_BUILDLINK3_MK)
GSM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsm+=	gsm>=1.0.10
BUILDLINK_ABI_DEPENDS.gsm+=	gsm>=1.0.12
BUILDLINK_PKGSRCDIR.gsm?=	../../audio/gsm
.endif # GSM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsm
