#!/usr/sbin/dtrace -s

pid$target::*NodeProcessor*:entry
{
	ts[probefunc] = timestamp;
}

pid$target::*NodeProcessor*:return
/ts[probefunc]/
{
	@ft[probefunc] = sum(timestamp - ts[probefunc]);
	ts[probefunc] = 0;
}

