# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.tdd_dictionary.Debug:
/Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/Debug/tdd_dictionary:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/Debug/tdd_dictionary


PostBuild.tdd_dictionary.Release:
/Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/Release/tdd_dictionary:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/Release/tdd_dictionary


PostBuild.tdd_dictionary.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/MinSizeRel/tdd_dictionary:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/MinSizeRel/tdd_dictionary


PostBuild.tdd_dictionary.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/RelWithDebInfo/tdd_dictionary:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/tdd_dictionary/build/xcode/RelWithDebInfo/tdd_dictionary


