# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.mark_and_toys.Debug:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/Debug/mark_and_toys:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/Debug/mark_and_toys


PostBuild.mark_and_toys.Release:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/Release/mark_and_toys:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/Release/mark_and_toys


PostBuild.mark_and_toys.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/MinSizeRel/mark_and_toys:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/MinSizeRel/mark_and_toys


PostBuild.mark_and_toys.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/RelWithDebInfo/mark_and_toys:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/xcode/RelWithDebInfo/mark_and_toys


