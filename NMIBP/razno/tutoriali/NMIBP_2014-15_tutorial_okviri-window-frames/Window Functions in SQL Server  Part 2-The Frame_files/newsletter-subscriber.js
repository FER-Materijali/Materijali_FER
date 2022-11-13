require(["jquery"], function ($) {
    var setUpNewsletterSignUp = function (element) {
        var newsletterId = element.attr("data-newsletter-signup");
        var emailField = element.find('input[type="email"]');
        var submitButton = element.find('input[type="submit"]');
        var messageSpan = element.find("*[data-newsletter-signup-message]");

        var displayMessage = function (message) {
            messageSpan.text(message);
        };

        var onSuccess = function () {
            displayMessage("Successfully signed up");
        };
        var onFailure = function () {
            displayMessage("Hmm, something went wrong, check your e-mail address and try again");
        };

        var submitRequest = function () {
            displayMessage("Signing you up...");
            $.ajax({
                url: "/newsletter/user-subscribe.aspx",
                type: "GET",
                data: {
                    lists: newsletterId,
                    email: emailField.val()
                },
                dataType: "jsonp",
                success: onSuccess,
                error: onFailure
            });
        };
        var handleFormSubmission = function (event) {
            event.preventDefault();
            submitRequest();
            return false;
        };
        emailField.on("keypress", function (event) {
            if (event.which === 13) {
                return handleFormSubmission(event);
            }
        });
        submitButton.on("click", handleFormSubmission);
        element.show();
    };

    $("*[data-newsletter-signup]").each(function (index, element) {
        setUpNewsletterSignUp($(element));
    });
});