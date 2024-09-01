
class User{
    
    private String userId;
    private String userName;
    private String UserEmailId;
    
    private User(UserBulider builder)
    {
        this.userId=builder.userId;
        this.userName=builder.userName;
        this.UserEmailId=builder.userEmailId;
    }
    
    public String getUserId()
    {
        return userId;
    }
    
    public String getUserNAme()
    {
        return userName;
    }
    
    public String getUserEmailId()
    {
        return UserEmailId;
    }
    
    public String toString()
    {
        return this.userName + " : " + this.userId + " : " + this.UserEmailId;
    }
    
    static class UserBulider{
        
          private String userId;
          private String userName;
          private String userEmailId;
        
        
        public UserBulider setUserId(String userId)
        {
            this.userId=userId;
            return this;
        }
        
        public UserBulider setUserName(String userName)
        {
            this.userName=userName;
            return this;
        }
        
        public UserBulider setUserEmailId(String userEmailId)
        {
            this.userEmailId=userEmailId;
            return this;
        }
        
        public User build()
        {
            return new User(this);
        }
    }
    
    
    
}



public class PrototypePattern
{
	public static void main(String[] args) {
	
	User user = new User.UserBulider().setUserEmailId("anandumbarkar@.com").setUserName("Anand").setUserId("122B2F155").build();
	
	System.out.println(user);	}
}
