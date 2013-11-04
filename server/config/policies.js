module.exports.policies = {

  // Default policy for all controllers and actions
  // (`true` allows public access) 
  '*': true,

    GroupController: {
        '*': 'authenticated',
        'create': ['authenticated', 'admin'],
        'manage': ['authenticated', 'admin'],
        'user_add': ['authenticated', 'admin'],
        'user_delete': ['authenticated', 'admin'],
        'destroy': ['authenticated', 'admin']
    },

    MainController: {
        'dashboard': 'authenticated'
    },

    MessageController: {
        '*': 'authenticated'
    },

    RoomController: {
        '*': 'authenticated',
        'create': ['authenticated', 'admin'],
        'manage': ['authenticated', 'admin'],
        'destroy': ['authenticated', 'admin'],
        'room_hook_github': true,
        'room_hook_bitbucket': true
    },

    UserController: {
        '*': 'authenticated',
        'manage': ['authenticated', 'admin'],
        'create': true
    }
};