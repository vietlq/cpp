# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.journey_to_the_moon.Debug:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/Debug/journey_to_the_moon:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/Debug/journey_to_the_moon


PostBuild.journey_to_the_moon.Release:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/Release/journey_to_the_moon:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/Release/journey_to_the_moon


PostBuild.journey_to_the_moon.MinSizeRel:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/MinSizeRel/journey_to_the_moon:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/MinSizeRel/journey_to_the_moon


PostBuild.journey_to_the_moon.RelWithDebInfo:
/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/RelWithDebInfo/journey_to_the_moon:
	/bin/rm -f /Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/xcode/RelWithDebInfo/journey_to_the_moon


