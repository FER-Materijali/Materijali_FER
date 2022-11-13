require(["jquery"], function ($) {
    $(document).ready(function () {
        $(".remove-comment").each(function (index, element) {
            setUpRemoveCommentButton($(element));
        });
    });

    function setUpRemoveCommentButton(element) {
        element.show();
        element.on("click", function () {
            var commentId = $(element).data("comment-id");
            removeComment(element, commentId);
        });
    }

    function removeComment(element, commentId) {
        $.post(
            "/community/ajax/RemoveComment.ashx",
            { 'comment-id': commentId },
            function (data) { markCommentAsRemoved(element, commentId); }
        );
    }

    function markCommentAsRemoved(element, commentId) {
        var commentTable = $(element).parents(".commenttable");
        commentTable.css({ position: 'relative' });
        var coverText = '<div class="comment-removed" data-comment-id="' + commentId + '">Comment Removed</div>'
        var cover = $(coverText);
        commentTable.append(cover);
        cover.css({ 'line-height': cover.height() + 'px' });
        cover.fadeIn();
    }
});