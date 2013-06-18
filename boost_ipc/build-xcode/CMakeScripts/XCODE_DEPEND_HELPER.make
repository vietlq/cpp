# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.boost_ipc.Debug:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Debug/boost_ipc:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Debug/boost_ipc


PostBuild.boost_ipc.Release:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Release/boost_ipc:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Release/boost_ipc


PostBuild.boost_ipc.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/MinSizeRel/boost_ipc:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/MinSizeRel/boost_ipc


PostBuild.boost_ipc.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/RelWithDebInfo/boost_ipc:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/RelWithDebInfo/boost_ipc


