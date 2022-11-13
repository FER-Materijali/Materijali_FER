require(["jquery"], function ($) {
    $(document).ready(function () {
        $("#RSSfeedwidget").show();
    });

    window.RssSelect = function(category) {
        if (category.value.indexOf("-") == -1) {
            $("input[name*='rss'][value^='" + category.value + "-']").each(function() {
                this.checked = category.checked
            });
        } else {
            if (category.checked == false) {
                $("input[name*='rss'][value='" + category.value.substring(0, category.value.indexOf("-")) + "']").each(function() {
                    this.checked = false;
                });
            }
        }
    };

    window.RssGetSide = function (isAdvanced) {
        if (isAdvanced == false && $("a#rssGetLink").length != 0) {
            var nCat = "?ncat";

            $("input[name*='rss']").each(function () {
                if (this.checked == false) {
                    nCat += (nCat == "?ncat" ? "=" : ",") + $(this).val();
                }
            });

            var baselink = $("a#rssGetLink").attr("href").substring(0, $("a#rssGetLink").attr("href").indexOf("rss.aspx") + 8);
            document.location.href = baselink + nCat;
        }

        if (isAdvanced == true && $("a#rssAdvLink").length != 0) {
            var sCat = "?scat";

            $("input[name*='rss']").each(function () {
                if (this.checked == true) {
                    sCat += (sCat == "?scat" ? "=" : ",") + $(this).val();
                }
            });

            var baselink = $("a#rssAdvLink").attr("href").substring(0, $("a#rssAdvLink").attr("href").indexOf("rsssel.aspx") + 11);
            document.location.href = baselink + sCat;
        }
    };

    window.RssGetMain = function () {
        if ($("a#rssGetLink").length != 0) {
            var nonCat = new Array();

            $("input[name*='rss']").each(function () {
                if ($(this).val().indexOf("-") == -1) {
                    if ($(this).val() == "B") { // blogs are special case as it has no children
                        if (this.checked == false) nonCat[nonCat.length] = $(this).val()
                    }
                    else {
                        var children = new Array();
                        var childSelected = false;
                        $("input[name*='rss'][value^='" + $(this).val() + "-']").each(function () {
                            if (this.checked == true) {
                                childSelected = true;
                            }
                            else {
                                children[children.length] = $(this).val().substring($(this).val().indexOf("-") + 1);
                            }
                        });
                        if (childSelected == false) {
                            nonCat[nonCat.length] = $(this).val();
                        }
                        else {
                            for (loop = 0; loop < children.length; loop++) {
                                nonCat[nonCat.length] = children[loop];
                            }
                        }
                    }
                }
            });

            var categories = "?ncat";
            $.each(nonCat, function (index, value) { categories += (categories == "?ncat" ? "=" : ",") + value; });

            var baselink = $("a#rssGetLink").attr("href").substring(0, $("a#rssGetLink").attr("href").indexOf("rss.aspx") + 8);
            document.location.href = baselink + categories;
        }
    };
});