from forum.models import Post
from flask import Blueprint, redirect, render_template, request, url_for
from flask_login import login_required, current_user
import git

main_bp = Blueprint('main_bp', __name__,
                    template_folder="templates",
                    static_folder="static")


@main_bp.route('/reload_server/', methods=['POST'])
def webhook():
    # Defines webhook for GitHub connection. Auto pull repo changes on server
    if request.method == 'POST':
        repo = git.Repo('./CSE106-Forum')
        origin = repo.remotes.origin
        origin.pull()
        return 'Pulled changes from GitHub to server!', 200
    else:
        return 'Wrong event type', 400


@main_bp.route('/', methods=['GET'])
def index():
    '''
    Defines Flask route to bring user to posts page

    Methods: GET
    '''

    # Take user to the teacher or student view based on role
    # if current_user.role == Role.PROFESSOR:
    #    return render_template('teacher.html')
    # elif current_user.role == Role.DEFAULT:
    #    return render_template('courses.html')

    # Return all-posts template if user passes checks
    return render_template('all-posts.html')


# 404 errors


@ main_bp.app_errorhandler(404)
def page_not_found(e):
    print(e)
    return redirect(url_for("main_bp.index"))


# 403 errors
@ main_bp.app_errorhandler(403)
def forbidden(e):
    print(e)
    return render_template('error/403.html'), 403


@ main_bp.route('/profile/', methods=['GET'])
@login_required
def profile():

    # Defines route for profile view

    # If admin accesses portal then take them to admin panel
    if current_user.is_admin():
        return redirect("/admin/")

    # Query the all posts belonging to user
    post = Post.query.filter(Post.user == current_user).all()
    posts = []
    # For every post in query, add to JSON to send to template
    for p in post:
        tags = []
        for tag in p.tags:
            tags.append(tag.type.value)

        post_content = ""
        for i in range(0, 3):
            post_content += p.content[:30]

        posts.append({"title": p.title,
                      "uri": p.uri,
                      "uuid": p.uuid,
                      "content": post_content,
                      "upvotes": p.upvotes,
                      "downvotes": p.downvotes,
                      "date": p.date,
                      "tags": tags})

    return render_template('profile.html', data=posts)
