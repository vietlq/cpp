#!/usr/sbin/dtrace -s

pid$target::*NodeProcessor*:entry
{
	key_ = ustack();
	ts[key_] = timestamp;
}

pid$target::*NodeProcessor*:return
/ts[ustack()]/
{
	key_ = ustack();
	@ft[key_] = sum(timestamp - ts[key_]);
	ts[key_] = 0;
}

