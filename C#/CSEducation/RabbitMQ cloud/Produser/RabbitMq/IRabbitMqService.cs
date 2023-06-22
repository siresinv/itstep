namespace Produser.RabbitMq
{
    public interface IRabbitMqService
    {
        void SendMessage(object obj);
        void SendMessage(string msg);
    }
}
