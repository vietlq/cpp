# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.kth_ancestor.Debug:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/Debug/kth_ancestor:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/Debug/kth_ancestor


PostBuild.kth_ancestor.Release:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/Release/kth_ancestor:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/Release/kth_ancestor


PostBuild.kth_ancestor.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/MinSizeRel/kth_ancestor:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/MinSizeRel/kth_ancestor


PostBuild.kth_ancestor.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/RelWithDebInfo/kth_ancestor:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/03-kth-ancestor/xcode/RelWithDebInfo/kth_ancestor


