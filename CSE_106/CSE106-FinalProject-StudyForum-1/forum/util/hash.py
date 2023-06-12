import uuid
from werkzeug.security import check_password_hash, generate_password_hash


def check_salt_hash(hash, password, salt):
    return check_password_hash(hash, password+salt)


def gen_salt_hash(password, salt, method="sha256"):
    return generate_password_hash(password+str(salt), method=method)


def gen_model_uuid(model, size=32):
    '''
    Generates new UUID for specified model and char length

    Parameters:
        model (db.Model): The model that the UUID will be generated for (must
        have uuid field)
        size (int): Lenght of the UUID

    Returns:
        uuid (str): Resulting UUID
    '''
    from forum import db

    temp_uuid = uuid.uuid4().hex[:size]
    exists = True

    while exists:
        exists = db.session.query(model.uuid).filter_by(
            uuid=temp_uuid).first() is not None
        temp_uuid = uuid.uuid4().hex[:size]

    return temp_uuid
