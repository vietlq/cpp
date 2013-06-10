# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.word_path.Debug:
/Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/Debug/word_path:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/Debug/word_path


PostBuild.word_path.Release:
/Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/Release/word_path:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/Release/word_path


PostBuild.word_path.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/MinSizeRel/word_path:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/MinSizeRel/word_path


PostBuild.word_path.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/RelWithDebInfo/word_path:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/WordPath/build/xcode/RelWithDebInfo/word_path


