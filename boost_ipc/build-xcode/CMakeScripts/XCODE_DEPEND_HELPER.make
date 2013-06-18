# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.boost_ipc_inspector.Debug:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Debug/boost_ipc_inspector:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Debug/boost_ipc_inspector


PostBuild.boost_ipc_modifier.Debug:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Debug/boost_ipc_modifier:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Debug/boost_ipc_modifier


PostBuild.boost_ipc_inspector.Release:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Release/boost_ipc_inspector:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Release/boost_ipc_inspector


PostBuild.boost_ipc_modifier.Release:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Release/boost_ipc_modifier:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/Release/boost_ipc_modifier


PostBuild.boost_ipc_inspector.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/MinSizeRel/boost_ipc_inspector:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/MinSizeRel/boost_ipc_inspector


PostBuild.boost_ipc_modifier.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/MinSizeRel/boost_ipc_modifier:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/MinSizeRel/boost_ipc_modifier


PostBuild.boost_ipc_inspector.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/RelWithDebInfo/boost_ipc_inspector:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/RelWithDebInfo/boost_ipc_inspector


PostBuild.boost_ipc_modifier.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/RelWithDebInfo/boost_ipc_modifier:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-xcode/RelWithDebInfo/boost_ipc_modifier


